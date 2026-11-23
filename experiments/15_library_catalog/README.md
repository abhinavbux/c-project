# Experiment 15 — Mini project — Library catalog

Run these commands from the repository root in PowerShell with a working GCC compiler.

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic experiments/15_library_catalog/main.c -o experiment15.exe
if ($LASTEXITCODE -eq 0) { .\experiment15.exe }
```

## How it works

1. The mini project is a library catalog with five operations: add a book, display the catalog, search by ID, update a title, and delete a book. It holds up to 50 books in memory for the current session.
2. Each Book has a unique positive ID and a title. The active catalog always occupies indexes 0 through count - 1. Adding a valid book fills the next slot. Deleting a book shifts later records left and reduces count.
3. The menu repeats until you select Exit or the input ends. The program rejects duplicate IDs, blank titles, overlong titles, and numbers outside the permitted ranges. An invalid operation returns to the menu, and a failed title update leaves the old title in place.
4. A pointer to count lets add_book and delete_book change the caller's count. A pointer to a specific Book lets update_title change that record directly. Search and display use const to indicate that they only read records.

## Try it

Enter each item on its own line, in this order.

`2` → `1` → `10` → `The Hobbit` → `1` → `20` → `Dune` → `1` → `10` → `3` → `10` → `4` → `10` → `The Hobbit Illustrated` → `2` → `5` → `10` → `3` → `10` → `2` → `6`

Look for these results.

```text
Catalog is empty.
That book ID already exists.
10 | The Hobbit
Title updated.
Catalog:
10 | The Hobbit Illustrated
20 | Dune
Book deleted.
Book not found.
Catalog:
20 | Dune
```
