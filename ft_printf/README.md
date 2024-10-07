# `ft_printf` -- Recreating part of the `C` printf function
This project recreates part of the `printf` function in `C`. Due to the various conversions required, this project requires some thought regarding the structure of the code.
## Learning Outcomes
### Challenges faced
- This project has quite a few special cases when you have interactions between conversions and flags.
- `ft_printf` should be able to handle variable arguments, a new concept which requires thought into code structure.
### Key Takeaways
- My approach to this project was rather haphazard. I ended up with a 'whack a mole' approach to fixing bugs, which in turn resulted in some pretty messy code.
### In Retrospect
- Spending some time planning out the interactions between the conversions and the flags would have resulted in better structured and readable code. This was a good lesson on technical debt.
## Features
### Conversions
| Conversion | Prints |
| -- | -- |
| `%c` | a single character |
| `%s` | a string |
| `%p` | a pointer in hexadecimal format. |
| `%d` | a decimal number. |
| `%i` | an integer |
| `%u` | an unsigned decimal |
| `%x` | a number in hexadecimal lowercase format. |
| `%X` | a number in hexadecimal uppercase format |
| `%%` | a percent sign |
### Flags
| Flag | Effect | Example | Output |
| -- | -- | -- | -- |
| `-` | Left justifies the output within the specified field width | `printf("\|%-10d\|\n", 42);` | `\|42        \|` |
| `0` | Pads the output with leading zeros within the field width | `printf("\|%010d\|\n", 42);` | `\|0000000042\|` |
| `#` | Display certain conversions in an alternate form | `printf("%#x\n", 255);` | `0xff` |
| `+` | Forces the plus sign to be shown for positive numbers | `printf("\|%+d\|\n", 42);` | `\|+42\|` |
| ` ` | (Space) Adds a space before positive numbers if no sign | `printf("\|% d\|\n", 42);` | `\| 42\|` |
| `.` | Specifies the number of digits after the dot for floats | `printf("%.2f\n", 3.14159);` | `3.14` |
## Installation and Usage
Simply run
```
make
```
Then use the `libftprintf.a` as needed.
