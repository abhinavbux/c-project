# Experiment 6 — Recursion

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/06_recursion/main.c -o experiment06.exe
if ($LASTEXITCODE -eq 0) { .\experiment06.exe }
```

## How it works

1. Every recursive function needs a base case that returns without another call. Factorial multiplies n by the result of calling itself with n - 1. For 4, the multiplication is 4 × 3 × 2 × 1 as the calls return.
2. Fibonacci uses base values F(0) = 0 and F(1) = 1. Each larger term is the sum of two smaller calls. This version repeats work, so the maximum index keeps the exercise quick.
3. The extra operation is Euclid's GCD. It repeatedly replaces (a, b) with (b, a % b). For (48, 18), the pairs become (18, 12), (12, 6), and (6, 0). The zero remainder ends the recursion.

## Try it

Enter each item on its own line, in this order.

`5` → `10` → `48` → `18`

Look for these results.

```text
5! = 120
Fibonacci(10) = 55
GCD(48, 18) = 6
```
