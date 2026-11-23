#include "../input.h"

static double add(double a, double b) { return a + b; }
static double subtract(double a, double b) { return a - b; }
static double multiply(double a, double b) { return a * b; }
static double divide(double a, double b) { return a / b; }

static unsigned long long factorial(int n)
{
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= (unsigned)i;
    }
    return result;
}

static int is_prime(int n)
{
    if (n < 2) {
        return 0;
    }
    for (int divisor = 2; divisor <= n / divisor; ++divisor) {
        if (n % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int choice;
    puts("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Factorial\n6. Prime check");
    if (!read_int("Choose an option: ", 1, 6, &choice)) {
        return 1;
    }
    if (choice == 5) {
        int n;
        if (!read_int("Factorial of (0-20): ", 0, 20, &n)) {
            return 1;
        }
        printf("Factorial = %llu\n", factorial(n));
    } else if (choice == 6) {
        int n;
        if (!read_int("Integer: ", -1000000000, 1000000000, &n)) {
            return 1;
        }
        printf("Prime: %s\n", is_prime(n) ? "yes" : "no");
    } else {
        double a, b, result;
        if (!read_double("First number: ", -1e100, 1e100, &a) ||
            !read_double("Second number: ", -1e100, 1e100, &b)) {
            return 1;
        }
        switch (choice) {
        case 1: result = add(a, b); break;
        case 2: result = subtract(a, b); break;
        case 3: result = multiply(a, b); break;
        default:
            if (b == 0.0) {
                puts("Cannot divide by zero.");
                return 1;
            }
            if (fabs(b) < 1.0 && fabs(a) / 1e300 > fabs(b)) {
                puts("Result exceeds the calculator's range.");
                return 1;
            }
            result = divide(a, b);
            break;
        }
        printf("Result = %.10g\n", result);
    }
    return 0;
}
