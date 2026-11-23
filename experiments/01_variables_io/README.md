# Experiment 1: Variables, Data Types, Operators and I/O

Your chosen applications are rectangle area/perimeter and temperature conversion.
This program runs the rectangle calculation first, then one temperature conversion.
It accepts decimal measurements and either uppercase or lowercase C/F.

## Build and run

Open a terminal in the repository root. With a working GCC installation:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/01_variables_io/main.c -o experiments/01_variables_io/experiment01.exe
.\experiments\01_variables_io\experiment01.exe
```

Compilation translates the C source into an executable. Running the executable
starts `main`. Recompile whenever you change the source.

## Walk through the code

1. `#include <stdio.h>` declares input/output functions such as `printf` and `scanf`.
   `<math.h>` supplies `isfinite`, used to reject infinity and NaN.
2. `int main(void)` is the entry point. `void` means it takes no arguments here;
   the `int` return value reports success or failure to the operating system.
3. `const int experiment_number = 1` stores a whole number that this program
   cannot change. `double` stores decimal measurements; `char` stores a scale letter.
4. `printf` prints prompts. `\n` starts a new line. `fflush(stdout)` makes sure a
   prompt without a newline is displayed before the program waits for input.
5. `scanf("%lf %lf", &length, &width)` reads two decimal numbers. `%lf` is the
   input format for `double`. `&length` means the address where the value is stored.
   Addresses will be studied properly in Experiment 11.
6. Checking `scanf`'s return value prevents using variables that were not read.
   The small `if` checks are an early preview of Experiment 2. `!=` means not equal;
   `||` means OR; `!` means NOT. Invalid input prints an explanation and exits.
7. `area = length * width` multiplies the dimensions and stores the answer.
   `perimeter = 2.0 * (length + width)` adds first because of the parentheses.
   Area uses square units; perimeter uses the original length unit.
8. `%.2f` displays a decimal value rounded to two places. It changes how the
   result looks, not the stored value. `printf` uses `%f` for `double`, while
   `scanf` uses `%lf` to read it. `%d` prints an `int`.
9. `scanf("%lf %c", &temperature, &scale)` reads a number and a character.
   The space before `%c` skips whitespace, including newlines. `%c` itself would
   otherwise read the next character even if that character were whitespace.
10. `==` compares values; `=` assigns a value. The branch selected by the letter
    applies `F = C * (9.0 / 5.0) + 32.0` or `C = (F - 32.0) * (5.0 / 9.0)`.
    Using `9 / 5` would give `1`, because both operands are integers.
11. `return 0` signals success. `return 1` signals an input error.

The program demonstrates addition, subtraction, multiplication, division and
assignment. Inputs are bounded by 1e100 (10 raised to 100) to keep arithmetic
within the range of `double`. This is a numerical conversion exercise, so negative
temperatures are allowed without imposing physical temperature limits.

## Example session

```text
Experiment 1: Measurements and temperature

RECTANGLE
Enter length and width in the same unit (example: 5 3): 5 3
Area = 15.00 square units
Perimeter = 16.00 units

TEMPERATURE
Enter a temperature followed by its scale (example: 25 C or 77 F): 25 C
25.00 C = 77.00 F
```

This is an expected-output example, not a captured execution transcript.

## Test cases

Run the program again for each case.

| Rectangle input | Temperature input | Expected result |
| --- | --- | --- |
| `5 3` | `25 C` | Area 15.00; perimeter 16.00; 77.00 F |
| `2.5 4` | `32 F` | Area 10.00; perimeter 13.00; 0.00 C |
| `1 1` | `-40 c` | Area 1.00; perimeter 4.00; -40.00 F |
| `1 1` | `212 f` | 100.00 C |
| `0 3` | Not requested | Reject invalid dimensions |
| `-2 3` | Not requested | Reject invalid dimensions |
| `abc` | Not requested | Reject nonnumeric input |
| `1 1` | `20 K` | Reject unsupported scale |
| `1 1` | `nan C` | Reject nonfinite temperature |
| `1e101 2` | Not requested | Reject dimensions above the supported limit |

Input follows scanf's token rules: trailing extra text is not comprehensively
validated. Errors exit instead of retrying. Full-line validation and retry loops
can be added after we cover strings and loops.

## Try it yourself

Before running, predict the area and perimeter for length 6 and width 4.
Then predict the Fahrenheit result for 0 C. Explain why `5 / 9` would break the
Fahrenheit-to-Celsius formula. Change `%.2f` to `%.3f` and observe the display.

## Verification status

Built with portable 64-bit GCC 16.2.0 using C11 and warnings treated as errors.
All ten cases above passed. The original 32-bit MinGW had a startup error in
Codex, so the build used the portable compiler.
