# Experiment 11 — Pointers

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/11_pointers/main.c -o experiment11.exe
if ($LASTEXITCODE -eq 0) { .\experiment11.exe }
```

## How it works

1. &a gives the address of a, and int *pointer stores the address of an int. *pointer reads the value at that address.
2. The optional swap takes two addresses. Writing *first updates the variable in main. The temporary variable saves the original first value until it can be written to the second.
3. Adding one to an int pointer moves by one int element. The loop stops at the position just beyond the array. It compares against that position and only reads from actual elements.

## Try it

Enter each item on its own line, in this order.

`12` → `-3`

Look for these results.

```text
Value of a through its pointer = 12
After swap: a = -3, b = 12
Offset 0: 10
Offset 1: 20
Offset 2: 30
```
