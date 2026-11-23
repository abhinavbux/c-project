#include <string.h>
#include "../input.h"

#define CAPACITY 50

typedef struct {
    int id;
    char title[80];
} Book;

static int find_book(const Book books[], int count, int id)
{
    for (int i = 0; i < count; ++i) {
        if (books[i].id == id) {
            return i;
        }
    }
    return -1;
}

static int read_title(char title[], int capacity)
{
    if (!read_line("Book title: ", title, capacity)) {
        return 0;
    }
    if (at_end(title)) {
        puts("A title is required.");
        return 0;
    }
    return 1;
}

static void print_book(const Book *book)
{
    printf("%d | %s\n", book->id, book->title);
}

static void add_book(Book books[], int *count)
{
    if (*count == CAPACITY) {
        puts("Catalog is full.");
        return;
    }
    Book book = {0};
    if (!read_int("New book ID (1-1000000): ", 1, 1000000, &book.id)) {
        return;
    }
    if (find_book(books, *count, book.id) >= 0) {
        puts("That book ID already exists.");
        return;
    }
    if (!read_title(book.title, sizeof book.title)) {
        return;
    }
    books[*count] = book;
    ++(*count);
    puts("Book added.");
}

static void display_books(const Book books[], int count)
{
    if (count == 0) {
        puts("Catalog is empty.");
        return;
    }
    puts("Catalog:");
    for (int i = 0; i < count; ++i) {
        print_book(&books[i]);
    }
}

static int select_book(const Book books[], int count)
{
    int id;
    if (!read_int("Book ID (1-1000000): ", 1, 1000000, &id)) {
        return -1;
    }
    int index = find_book(books, count, id);
    if (index < 0) {
        puts("Book not found.");
    }
    return index;
}

static void update_title(Book *book)
{
    char title[sizeof book->title];
    if (read_title(title, sizeof title)) {
        strcpy(book->title, title);
        puts("Title updated.");
    }
}

static void delete_book(Book books[], int *count, int index)
{
    for (int i = index; i < *count - 1; ++i) {
        books[i] = books[i + 1];
    }
    --(*count);
    puts("Book deleted.");
}

int main(void)
{
    Book books[CAPACITY];
    int count = 0;
    puts("Library catalog (records stay in memory until exit).");

    for (;;) {
        int choice;
        puts("\n1. Add book\n2. Display catalog\n3. Search by ID\n"
             "4. Update title\n5. Delete book\n6. Exit");
        if (!read_int("Choose an option: ", 1, 6, &choice)) {
            if (ferror(stdin)) {
                return 1;
            }
            if (feof(stdin)) {
                return 0;
            }
            continue;
        }
        switch (choice) {
        case 1:
            add_book(books, &count);
            break;
        case 2:
            display_books(books, count);
            break;
        case 3:
        case 4:
        case 5: {
            int index = select_book(books, count);
            if (index >= 0) {
                if (choice == 3) {
                    print_book(&books[index]);
                } else if (choice == 4) {
                    update_title(&books[index]);
                } else {
                    delete_book(books, &count, index);
                }
            }
            break;
        }
        case 6:
            return 0;
        }
        if (ferror(stdin)) {
            return 1;
        }
        if (feof(stdin)) {
            return 0;
        }
    }
}
