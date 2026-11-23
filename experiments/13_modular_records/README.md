# Experiment 13 — Integrated modular programming

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/13_modular_records/main.c experiments/13_modular_records/records.c -o experiment13.exe
if ($LASTEXITCODE -eq 0) { .\experiment13.exe }
```

## How it works

1. main.c handles the menu and the user's input. records.h describes the Employee type and function declarations. records.c implements searching, printing, and sorting. The compiler must link both .c files to build the program.
2. The count starts at zero and increases only when a validated employee is added. A duplicate ID leaves the array unchanged. Display and search use only the entries before count.
3. The extra operation sorts by ID using insertion sort. Take the next record, shift larger IDs one slot to the right, and put the record in the space left behind. Records stay in memory until exit.

## Try it

Enter each item on its own line, in this order.

`2` → `1` → `20` → `Grace Hopper` → `1` → `10` → `Ada Lovelace` → `1` → `20` → `3` → `20` → `4` → `2` → `5`

Look for these results.

```text
No employees yet.
That ID already exists.
Employee found:
20 | Grace Hopper
Sorted by ID.
10 | Ada Lovelace
20 | Grace Hopper
```
