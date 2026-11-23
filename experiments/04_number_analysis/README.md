# Experiment 4 — Number based computational problems

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/04_number_analysis/main.c -o experiment04.exe
if ($LASTEXITCODE -eq 0) { .\experiment04.exe }
```

## How it works

1. Remainder by 10 gets the rightmost digit. Integer division by 10 removes it. Starting the loop with do makes it process the number 0 once.
2. To append a digit to the reverse, multiply the accumulated result by 10 and add that digit. For 120, the reversal is numerically 21. A negative sign is kept on the reverse and excluded from digit sum. Negative inputs are treated as non-palindromes.
3. The optional check is primality. Numbers below 2 are excluded. If a divisor exists, one is at most the square root, so the loop can stop when divisor exceeds number / divisor.

## Try it

Enter each item on its own line, in this order.

`121`

Look for these results.

```text
Reverse = 121
Digit sum = 4
Palindrome: yes
Prime: no
```
