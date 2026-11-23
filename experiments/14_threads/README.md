# Experiment 14 — Basic multithreading

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/14_threads/main.c -o experiment14.exe -pthread
if ($LASTEXITCODE -eq 0) { .\experiment14.exe }
```

## How it works

1. A thread runs a function independently. This program starts two C11 threads that can run in either order. One adds 1 through n. The other adds their squares.
2. Each worker receives the address of its own Task, which contains its input and result. The workers write to different records, so they can do their calculations independently.
3. The main thread joins both workers before reading their results. A join waits for a worker to finish, which also makes the printed results appear in a consistent order. This experiment needs compiler support for the C11 threads.h header.

## Try it

Enter each item on its own line, in this order.

`5`

Look for these results.

```text
Worker 1 sum: 15
Worker 2 sum of squares: 55
```
