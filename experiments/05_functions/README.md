# Experiment 5 — User defined functions

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/05_functions/main.c -o experiment05.exe
if ($LASTEXITCODE -eq 0) { .\experiment05.exe }
```

## How it works

1. main is responsible for reading input and choosing the operation. Separate functions handle addition, subtraction, multiplication, division, factorial, and primality.
2. In add(a, b), the values supplied by main are arguments. The variables declared in add's definition are parameters. The returned value can be assigned or printed directly.
3. Factorial returns a large unsigned integer. is_prime returns 1 for true and 0 for false. The division branch checks its inputs before calling divide.

## Try it

Enter each item on its own line, in this order.

`1` → `2.5` → `3`

Look for these results.

```text
Result = 5.5
```
