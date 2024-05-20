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
                print!("Error: Unrecognized symbol {c}\n");
                return false;
            }
        };
    }
    return true;
}

fn print_tokens_err(tokens: &mut Vec<&str>, pos: usize, mes: &str) {
    let mut len = 0;
    let last_len = tokens.get(pos).expect("out of range").len();
    for (i, s) in tokens.iter().enumerate() {
        print!("{s} ");
        if i < pos {
            len += s.len() + 1;
        }
    }
    print!("\n{: <1$}", "", len);
    print!("{:^<1$}_", "", last_len);
    println!("{mes}");
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

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        print!("Invalid number of arguments\n");
        return;
    }

    let mut tokens: Vec<&str> = Vec::new();
    if !extract_tokens(&mut tokens, &args[1]) {
        return;
    }

    let mut poly = BTreeMap::new();

    let mut cur_coef = Coef { num: 1.0, exp: 0 };
    let mut prev = TokenType::Edge;
    let mut equal_dir = 1.0;
    for (i, s) in tokens.iter().enumerate() {
        let token_type = get_token_type(s);
        if matches!(token_type, TokenType::Invalid) {
            print_tokens_err(&mut tokens, i, "Invalid token\n");
            return;
        }
        let mut right = TokenType::Edge;
        if i + 1 < tokens.len() {
            right = get_token_type(tokens.get(i + 1).expect("Out of range"));
            if matches!(right, TokenType::Invalid) {
                print_tokens_err(&mut tokens, i + 1, "Invalid token\n");
                return;
            }
        }
        if !validate_token(&prev, &token_type, &right) {
            print_tokens_err(&mut tokens, i, "Incorrect token placement\n");
            return;
        }
        match token_type {
            TokenType::X => {
                if !matches!(right, TokenType::Pow) {
                    cur_coef.exp = cur_coef.exp + 1
                }
            }
            TokenType::Plus => add_coef_update(&mut poly, &mut cur_coef, equal_dir),
            TokenType::Minus => {
                match prev {
                    TokenType::Times | TokenType::Edge | TokenType::Equal => (),
                    _ => add_coef_update(&mut poly, &mut cur_coef, equal_dir),
                };
                cur_coef.num = cur_coef.num * -1.0;
            }
            TokenType::Num => {
                if matches!(prev, TokenType::Pow) {
                    cur_coef.exp = cur_coef.exp
                        + match s.parse::<u32>() {
                            Ok(n) => n,
                            Err(_) => {
                                print_tokens_err(
                                    &mut tokens,
                                    i,
                                    "Expected unsigned int for exponent\n",
                                );
                                return;
                            }
                        };
                } else {
                    cur_coef.num = cur_coef.num
                        * match s.parse::<f64>() {
                            Ok(n) => n,
                            Err(_) => {
                                print_tokens_err(&mut tokens, i, "Expected float for constant\n");
                                return;
                            }
                        };
                }
            }
            TokenType::Equal => {
                add_coef_update(&mut poly, &mut cur_coef, equal_dir);
                equal_dir *= -1.0;
                if equal_dir == 1.0 {
                    print_tokens_err(&mut tokens, i, "Duplicate Equal Sign\n");
                    return;
                }
            }
            _ => {}
        };
        prev = token_type;
    }

    add_coef_update(&mut poly, &mut cur_coef, equal_dir);

    let mut prev = false;
    for (_key, value) in &poly {
        if value.num >= 0.0 {
            if prev {
                print!(" + ");
            }
            print!("{}", value.num);
        } else {
            print!(" - {}", value.num * -1.0);
        }
        print!(" * X^{}", value.exp);
        prev = true;
    }
    if !prev {
        print!("0");
    }
    print!(" = 0\n");
}
