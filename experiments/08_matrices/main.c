#include "../input.h"

#define MAX_SIZE 10

int main(void)
{
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE];
    int rows, columns;
    if (!read_int("Rows (1-10): ", 1, MAX_SIZE, &rows) ||
        !read_int("Columns (1-10): ", 1, MAX_SIZE, &columns)) {
        return 1;
    }

    puts("Enter matrix A one element at a time, by row.");
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (!read_int("A element: ", -1000000, 1000000, &a[row][column])) {
                return 1;
            }
        }
    }
    puts("Enter matrix B with the same dimensions.");
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (!read_int("B element: ", -1000000, 1000000, &b[row][column])) {
                return 1;
            }
        }
    }

    puts("Matrix A:");
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            printf("%s%d", column == 0 ? "" : " ", a[row][column]);
        }
        putchar('\n');
    }
    puts("Matrix B:");
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            printf("%s%d", column == 0 ? "" : " ", b[row][column]);
        }
        putchar('\n');
    }
    puts("A + B:");
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            printf("%s%d", column == 0 ? "" : " ", a[row][column] + b[row][column]);
        }
        putchar('\n');
    }
    puts("Transpose of A:");
    for (int row = 0; row < columns; ++row) {
        for (int column = 0; column < rows; ++column) {
            printf("%s%d", column == 0 ? "" : " ", a[column][row]);
        }
        putchar('\n');
    }
    return 0;
}
