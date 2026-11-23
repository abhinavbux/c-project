# Experiment 8 — Two dimensional arrays and matrices

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/08_matrices/main.c -o experiment08.exe
if ($LASTEXITCODE -eq 0) { .\experiment08.exe }
```

## How it works

1. An element at row r and column c is a[r][c]. The inner loop finishes all columns for a row before the outer loop moves to the next row.
2. Addition requires equal dimensions and combines entries at the same coordinates. The program asks for the shared dimensions once.
3. The optional operation is transpose of A. It reads the original indices in reverse order. A 2 by 3 input produces a 3 by 2 transpose.

## Try it

Enter each item on its own line, in this order.

`2` → `3` → `1` → `2` → `3` → `4` → `5` → `6` → `6` → `5` → `4` → `3` → `2` → `1`

Look for these results.

```text
Matrix A:
1 2 3
4 5 6
Matrix B:
6 5 4
3 2 1
A + B:
7 7 7
7 7 7
Transpose of A:
1 4
2 5
3 6
```
