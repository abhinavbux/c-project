# Experiment 2 — Conditional Statements

The program shows a menu and performs one operation per run. Your optional
application is a simple calculator. The other options classify an integer
by sign, check whether it is even or odd, and find the largest of three integers.

## Run it in PowerShell

Open PowerShell in the repository folder and use a working GCC installation.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/02_conditionals/main.c -o experiment02.exe
if ($LASTEXITCODE -eq 0) { .\experiment02.exe }
```

## Follow the decisions

1. The program reads a menu number between 1 and 4. The outer switch runs
   the matching case. A break ends that case so the next one does not run.
   The menu runs once to keep the focus on branching. Repeating a menu with
   a loop is a natural follow-up after Experiment 3.
2. The sign check tests whether the number is greater than zero, then whether
   it is less than zero. If both conditions are false, the number is zero.
3. The percent operator gives the remainder. An integer is even when the
   remainder after division by 2 is zero. For example, -7 is odd because
   its remainder is -1. Testing for a remainder of 1 would miss it.
4. To find the largest, first test whether a is at least as large as both
   b and c. The && operator requires both comparisons to be true. If that
   branch does not run, compare b and c. Using >= handles ties.
5. The calculator reads two decimal numbers and a single operator. A second
   switch runs +, -, *, or /. Its default branch catches other operators.
   For division, an if checks for zero before doing the arithmetic.
   Another check keeps extreme quotients within the calculator's range.
6. The input helper in the parent folder reads one line at a time and checks
   that the entire number is valid and in range. The & before a variable
   passes its address so the helper can store the result, just as scanf did
   in Experiment 1. You can follow the branching in main.c before studying
   the helper's string parsing and pointers in later experiments.

## Inputs to try

Enter each value on its own line.

| Menu choice | Inputs in order | Expected answer |
| --- | --- | --- |
| 1 | -12 | Negative |
| 1 | 0 | Zero |
| 2 | -7 | Odd |
| 2 | 0 | Even |
| 3 | -5, -2, -2 | Largest = -2 |
| 4 | 8.5, /, 2 | Result = 4.25 |
| 4 | 8, /, 0 | Cannot divide by zero |
| 4 | 8, ^, 2 | Unknown operator |

Predict which condition wins when all three values in option 3 are equal.
Then try it with three 7s and trace which lines run.

## Verification

Built with portable 64-bit GCC 16.2.0 using C11 and warnings treated as errors.
All 19 checks passed, including negative values, ties, the four calculator
operations, division by zero, and malformed input.
