# Experiment 3 — Loops and nested control structures

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/03_loops/main.c -o experiment03.exe
if ($LASTEXITCODE -eq 0) { .\experiment03.exe }
```

## How it works

1. A for loop has a starting value, a condition to keep going, and an update. The table starts at 1 and stops after 10.
2. The factorial starts at 1 and multiplies by each integer from 2 through n. If n is 0, the loop takes no steps and the result stays 1. Limiting n to 20 keeps the product in range.
3. The outer loop picks the row. The inner loop prints as many stars as the row number. The newline belongs after the inner loop so each row stays together.

## Try it

Enter each item on its own line, in this order.

`7` → `5` → `3`

Look for these results.

```text
7 x 10 = 70
5! = 120
*
**
***
```
