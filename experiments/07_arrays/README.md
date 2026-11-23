# Experiment 7 — One dimensional arrays

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/07_arrays/main.c -o experiment07.exe
if ($LASTEXITCODE -eq 0) { .\experiment07.exe }
```

## How it works

1. An array stores values of one type. The first index is 0, so count elements have indexes 0 through count - 1.
2. Start minimum and maximum at the first stored value. Starting them at zero would give a wrong maximum for a list of entirely negative numbers.
3. Casting sum to double preserves fractional averages. The optional reversal swaps the first and last values, then moves the two indexes inward.

## Try it

Enter each item on its own line, in this order.

`4` → `-2` → `10` → `3` → `0`

Look for these results.

```text
Sum = 11
Average = 2.75
Minimum = -2
Maximum = 10
Reversed: 0 3 10 -2
```
