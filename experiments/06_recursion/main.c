#include "../input.h"

static unsigned long long factorial(unsigned n)
{
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

static unsigned fibonacci(unsigned n)
{
    if (n < 2) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

static int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(void)
{
    int n, index, a, b;
    if (!read_int("Factorial of (0-20): ", 0, 20, &n) ||
        !read_int("Fibonacci index (0-30): ", 0, 30, &index) ||
        !read_int("First nonnegative integer for GCD: ", 0, 1000000000, &a) ||
        !read_int("Second nonnegative integer for GCD: ", 0, 1000000000, &b)) {
        return 1;
    }
    if (a == 0 && b == 0) {
        puts("GCD requires at least one nonzero number.");
        return 1;
    }

    printf("%d! = %llu\n", n, factorial((unsigned)n));
    printf("Fibonacci(%d) = %u\n", index, fibonacci((unsigned)index));
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
    return 0;
}
