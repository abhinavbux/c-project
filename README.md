# C Programming Experiments

All 15 assignment experiments have C source and an explanation. Each folder includes build commands and an example to try.

| Experiment | Topic |
| --- | --- |
| 1 | [Variables, data types, operators and I/O](experiments/01_variables_io/README.md) |
| 2 | [Conditional statements](experiments/02_conditionals/README.md) |
| 3 | [Loops and nested control structures](experiments/03_loops/README.md) |
| 4 | [Number based computational problems](experiments/04_number_analysis/README.md) |
| 5 | [User defined functions](experiments/05_functions/README.md) |
| 6 | [Recursion](experiments/06_recursion/README.md) |
| 7 | [One dimensional arrays](experiments/07_arrays/README.md) |
| 8 | [Two dimensional arrays and matrices](experiments/08_matrices/README.md) |
| 9 | [Strings](experiments/09_strings/README.md) |
| 10 | [Searching and sorting](experiments/10_search_sort/README.md) |
| 11 | [Pointers](experiments/11_pointers/README.md) |
| 12 | [Structures and typedef](experiments/12_structures/README.md) |
| 13 | [Integrated modular programming](experiments/13_modular_records/README.md) |
| 14 | [Basic multithreading](experiments/14_threads/README.md) |
| 15 | [Mini project — Library catalog](experiments/15_library_catalog/README.md) |

## Build and run

Open PowerShell at the repository root and use the compiler commands in the experiment's README. Each experiment is a separate executable. Experiment 13 has two source files, and Experiment 14 needs a GCC toolchain with C11 thread support.

With a working GCC on PATH, build Experiment 3 like this.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/03_loops/main.c -o experiment03.exe
if ($LASTEXITCODE -eq 0) { .\experiment03.exe }
```

The commands were verified with portable 64-bit GCC 16.2.0. If your older GCC gives a DLL relocation error in Codex, use the working compiler's full path in place of `gcc`, preceded by `&` in PowerShell.

## GitHub Desktop

The Changes tab shows the source and documentation edits. A commit saves a local checkpoint. A push uploads committed changes to GitHub. Generated executables are ignored by Git.
