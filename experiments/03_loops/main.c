#include "../input.h"

int main(void)
{
    int number, n, height;
    if (!read_int("Multiplication table for: ", -10000, 10000, &number) ||
        !read_int("Factorial of (0-20): ", 0, 20, &n) ||
        !read_int("Star triangle height (1-20): ", 1, 20, &height)) {
        return 1;
    }

    for (int i = 1; i <= 10; ++i) {
        printf("%d x %d = %d\n", number, i, number * i);
    }

    unsigned long long factorial = 1;
    for (int i = 2; i <= n; ++i) {
        factorial *= (unsigned)i;
    }
    printf("%d! = %llu\n", n, factorial);

    for (int row = 1; row <= height; ++row) {
        for (int column = 1; column <= row; ++column) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}
