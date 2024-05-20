use core::f64;
use std::collections::BTreeMap;
use std::env;

#[derive(Debug)]
struct Coef {
    num: f64,
    exp: u32,
}

impl std::fmt::Display for Coef {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "{} * X^{}", self.num, self.exp)
    }
}

enum CharType {
    Seperator,
    Value,
    Invalid,
}

#[derive(PartialEq, Debug)]
enum TokenType {
    Plus,
    Minus,
    Times,
    Pow,
    Num,
    Equal,
    X,
    Invalid,
    Edge,
}

struct Complex {
    real: f64,
    imaginary: f64,
}

fn get_token_type(s: &str) -> TokenType {
    match s {
        "=" => TokenType::Equal,
        "X" => TokenType::X,
        "-" => TokenType::Minus,
        "+" => TokenType::Plus,
        "^" => TokenType::Pow,
        "." => TokenType::Invalid,
        "*" => TokenType::Times,
        _ => {
            if s.contains("X") {
                return TokenType::Invalid;
            }
            TokenType::Num
        }
    }
}

fn validate_token(left: &TokenType, cur: &TokenType, right: &TokenType) -> bool {
    let x = &TokenType::X;
    let n = &TokenType::Num;
    let m = &TokenType::Minus;
    // let pw = &TokenType::Pow;
    // let p = &TokenType::Plus;
    // let e = &TokenType::Equal;
    match cur {
        TokenType::Plus => (left == x || left == n) && (right == x || right == n),
        TokenType::Minus => right == x || right == n,
        TokenType::Times => (right == m || right == n || right == x) && left != &TokenType::Edge,
        TokenType::Pow => left == x && right == n,
        TokenType::Num => right != n && left != n && right != x && left != x,
        TokenType::Equal => {
            (left == n || left == x)
                && (right == n || right == x || right == m || right == &TokenType::Plus)
        }
        TokenType::X => {
            right != x && left != x && left != &TokenType::Pow && right != n && left != n
        }
        _ => false,
    }
}

fn get_char_type(c: char) -> CharType {
    match c {
        '0'..='9' | 'X' | '.' => CharType::Value,
        '+' | '-' | '*' | '^' | ' ' | '=' => CharType::Seperator,
        _ => CharType::Invalid,
    }
}

fn extract_tokens<'a>(tokens: &mut Vec<&'a str>, input: &'a String) -> bool {
    let mut sub_start = 0;
    let mut in_sub = false;
    for (i, c) in input.chars().enumerate() {
        match get_char_type(c) {
            CharType::Seperator => {
                if in_sub {
                    tokens.push(&input[sub_start..i])
                }
                in_sub = false;
                if c != ' ' {
                    tokens.push(&input[i..i + 1])
                }
            }
            CharType::Value => {
                if !in_sub {
                    sub_start = i;
                }
                in_sub = true;
                if i == input.len() - 1 {
                    tokens.push(&input[sub_start..i + 1])
                }
            }
            CharType::Invalid => {
                println!("\n\x1b[31mPARSING ERROR\x1b[0m");
                println!("Error: Unrecognized symbol {c}");
                return false;
            }
        };
    }
    return true;
}

fn print_tokens_err(tokens: &mut Vec<&str>, pos: usize, mes: &str) {
    let mut len = 0;
    let last_len = tokens.get(pos).expect("out of range").len();
    println!("\n\x1b[31mPARSING ERROR\x1b[0m");
    for (i, s) in tokens.iter().enumerate() {
        print!("{s} ");
        if i < pos {
            len += s.len() + 1;
        }
    }
    print!("\n\x1b[93m{: <1$}", "", len);
    print!("{:^<1$}_", "", last_len);
    println!("{mes}\x1b[0m");
}

fn add_coef(poly: &mut BTreeMap<u32, Coef>, coef: &mut Coef, dir: f64) {
    if coef.num == 0.0 {
        return;
    }
    match poly.get(&coef.exp) {
        Some(old) => {
            let temp = Coef {
                num: old.num + (coef.num * dir),
                exp: coef.exp,
            };
            if temp.num == 0.0 {
                poly.remove(&coef.exp);
                return;
            }
            poly.insert(coef.exp, temp);
            coef.exp = 0
        }
        None => {
            let temp = Coef {
                num: coef.num * dir,
                exp: coef.exp,
            };
            poly.insert(coef.exp, temp);
        }
    }
}

fn add_coef_update(poly: &mut BTreeMap<u32, Coef>, coef: &mut Coef, dir: f64) {
    add_coef(poly, coef, dir);
    coef.exp = 0;
    coef.num = 1.0;
}

fn convert_tokens_poly(poly: &mut BTreeMap<u32, Coef>, tokens: &mut Vec<&str>) -> bool {
    let mut cur_coef = Coef { num: 1.0, exp: 0 };
    let mut prev = TokenType::Edge;
    let mut equal_dir = 1.0;
    for (i, s) in tokens.iter().enumerate() {
        let token_type = get_token_type(s);
        if matches!(token_type, TokenType::Invalid) {
            print_tokens_err(tokens, i, "Invalid token\n");
            return false;
        }
        let mut right = TokenType::Edge;
        if i + 1 < tokens.len() {
            right = get_token_type(tokens.get(i + 1).expect("Out of range"));
            if matches!(right, TokenType::Invalid) {
                print_tokens_err(tokens, i + 1, "Invalid token\n");
                return false;
            }
        }
        if !validate_token(&prev, &token_type, &right) {
            print_tokens_err(tokens, i, "Incorrect token placement\n");
            return false;
        }
        match token_type {
            TokenType::X => {
                if !matches!(right, TokenType::Pow) {
                    cur_coef.exp = cur_coef.exp + 1
                }
            }
            TokenType::Plus => add_coef_update(poly, &mut cur_coef, equal_dir),
            TokenType::Minus => {
                match prev {
                    TokenType::Times | TokenType::Edge | TokenType::Equal => (),
                    _ => add_coef_update(poly, &mut cur_coef, equal_dir),
                };
                cur_coef.num = cur_coef.num * -1.0;
            }
            TokenType::Num => {
                if matches!(prev, TokenType::Pow) {
                    cur_coef.exp = cur_coef.exp
                        + match s.parse::<u32>() {
                            Ok(n) => n,
                            Err(_) => {
                                print_tokens_err(tokens, i, "Expected unsigned int for exponent\n");
                                return false;
                            }
                        };
                } else {
                    cur_coef.num = cur_coef.num
                        * match s.parse::<f64>() {
                            Ok(n) => n,
                            Err(_) => {
                                print_tokens_err(tokens, i, "Expected float for constant\n");
                                return false;
                            }
                        };
                }
            }
            TokenType::Equal => {
                add_coef_update(poly, &mut cur_coef, equal_dir);
                equal_dir *= -1.0;
                if equal_dir == 1.0 {
                    print_tokens_err(tokens, i, "Duplicate Equal Sign\n");
                    return false;
                }
            }
            _ => {}
        };
        prev = token_type;
    }

    add_coef_update(poly, &mut cur_coef, equal_dir);
    if equal_dir == 1.0 {
        println!("\n\x1b[31mPARSING ERROR\x1b[0m");
        println!("What was provided was not an equation (no equal sign)");
        return false;
    }
    return true;
}

fn get_or_zero(poly: &BTreeMap<u32, Coef>, val: u32) -> f64 {
    match poly.get(&val) {
        Some(n) => n.num,
        None => 0.0,
    }
}

fn solve_quaderatic(a: f64, b: f64, c: f64) -> (Complex, Complex) {
    let discriminant = b * b - (4.0 * a * c);
    if discriminant < 0.0 {
        return (
            Complex {
                real: -b / 2.0 / a,
                imaginary: (-discriminant).sqrt() / 2.0 / a,
            },
            Complex {
                real: -b / 2.0 / a,
                imaginary: -(-discriminant).sqrt() / 2.0 / a,
            },
        );
    }
    return (
        Complex {
            real: (-b + discriminant.sqrt()) / 2.0 / a,
            imaginary: 0.0,
        },
        Complex {
            real: (-b - discriminant.sqrt()) / 2.0 / a,
            imaginary: 0.0,
        },
    );
}

fn solve_polynomial(poly: &BTreeMap<u32, Coef>, max_degree: u32) {
    match max_degree {
        0 => match get_or_zero(&poly, 0) {
            0.0 => println!("THERE IS AN INFINITE NUMBER OF SOLUTIONS"),
            _ => println!("THERE IS NO SOLUTION"),
        },
        1 => {
            println!(
                "The solution is {}\n",
                -get_or_zero(&poly, 0) / get_or_zero(&poly, 1)
            )
        }
        2 => {
            let solutions = solve_quaderatic(
                get_or_zero(&poly, 2),
                get_or_zero(&poly, 1),
                get_or_zero(&poly, 0),
            );
            if solutions.0.imaginary != 0.0 {
                println!("Discriminant is negative. Solutions are imaginary:");
                println!("{} + {}i", solutions.0.real, solutions.0.imaginary);
                println!("{} + {}i", solutions.1.real, solutions.1.imaginary)
            } else if solutions.0.real == solutions.1.real {
                println!("Discriminant is zero. There is one repeated solution:");
                println!("{}", solutions.0.real);
            } else {
                println!("Discriminant is positive. Solutions are real:");
                println!("{}", solutions.0.real);
                println!("{}", solutions.1.real)
            }
        }
        _ => {
            println!("Degree is too large, can't solve.")
        }
    }
}

fn print_poly(poly: &BTreeMap<u32, Coef>) -> u32 {
    print!("Reduced form:     ");
    let mut prev = false;
    let mut max_degree: u32 = 0;
    for (_key, value) in poly {
        if value.exp > max_degree {
            max_degree = value.exp;
        }
        match (value.num >= 0.0, prev) {
            (false, _) => print!(" - "),
            (true, false) => print!(" "),
            (true, true) => print!(" + "),
        };
        if (value.num != 1.0 && value.num != -1.0) || value.exp == 0 {
            if value.num >= 0.0 {
                print!("{}", value.num);
            } else {
                print!("{}", value.num * -1.0);
            }
            if value.exp != 0 {
                print!(" * ");
            }
        }
        match value.exp {
            0 => {}
            1 => print!("X"),
            other => print!("X^{}", other),
        }
        prev = true;
    }
    if !prev {
        print!("0");
    }
    println!(" = 0");
    return max_degree;
}

fn process_polynomial(input: &String) {
    let mut tokens: Vec<&str> = Vec::new();
    if !extract_tokens(&mut tokens, &input) {
        return;
    }

    let mut poly = BTreeMap::new();
    if !convert_tokens_poly(&mut poly, &mut tokens) {
        return;
    }

    let max_degree = print_poly(&poly);
    println!("Polynomial degree: {max_degree}");

    solve_polynomial(&poly, max_degree);
}

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        println!("Invalid number of arguments");
        return;
    }
    process_polynomial(&args[1]);
}
