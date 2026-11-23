# Experiment 9 — Strings

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/09_strings/main.c -o experiment09.exe
if ($LASTEXITCODE -eq 0) { .\experiment09.exe }
```

## How it works

1. A C string ends at the null character. Walking to that terminator gives the length without calling strlen or other string manipulation functions.
2. The classification treats ASCII letters in either case as letters. A space means the literal space character. Length and reversal operate on bytes, so use ASCII text for this exercise.
3. The optional operations are reverse and palindrome checks. Reversal prints bytes from the last index to the first. The palindrome check compares opposing positions and uses exact case and spacing. Empty input is a palindrome by this definition.

## Try it

Enter each item on its own line, in this order.

`AbE 7!`

Look for these results.

```text
Length = 6
Vowels = 2
Consonants = 1
Digits = 1
Spaces = 1
Reverse: !7 EbA
Palindrome: no
```
