# Experiment 10 — Searching and sorting

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/10_search_sort/main.c -o experiment10.exe
if ($LASTEXITCODE -eq 0) { .\experiment10.exe }
```

## How it works

1. Linear search scans the original array from left to right and stops at the first match.
2. Bubble sort swaps adjacent values that are out of order. Each full pass moves the largest remaining value to the end. A pass with no swaps means the array is sorted.
3. Binary search halves the remaining range each time. This version first finds the earliest position that could contain the target, then checks equality. With duplicates both searches return the first matching index in the array they searched.

## Try it

Enter each item on its own line, in this order.

`5` → `7` → `1` → `7` → `-2` → `4` → `7`

Look for these results.

```text
Sorted: -2 1 4 7 7
original array: index 0
sorted array: index 3
```
