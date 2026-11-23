# Experiment 12 — Structures and typedef

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/12_structures/main.c -o experiment12.exe
if ($LASTEXITCODE -eq 0) { .\experiment12.exe }
```

## How it works

1. A structure groups related fields even when the fields have different types. Here every student has an integer roll number, a name string, and decimal marks.
2. The optional typedef gives the structure the type name Student. Student students[20] stores up to 20 records. The expression students[i].marks selects one field of one record.
3. The program searches by roll number, which is unique. It reads names as whole lines so a full name can contain spaces.

## Try it

Enter each item on its own line, in this order.

`2` → `10` → `Ada Lovelace` → `96.5` → `21` → `Grace Hopper` → `98` → `21`

Look for these results.

```text
10 | Ada Lovelace | 96.50
Found: 21 | Grace Hopper | 98.00
```
