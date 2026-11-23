#include <limits.h>
#include "../input.h"

int main(void)
{
    int choice, number, a, b, c;
    puts("1. Sign\n2. Even or odd\n3. Largest of three\n4. Simple calculator");
    if (!read_int("Choose an option: ", 1, 4, &choice)) {
        return 1;
    }

    switch (choice) {
    case 1:
        if (!read_int("Number: ", INT_MIN, INT_MAX, &number)) {
            return 1;
        }
        if (number > 0) {
            puts("Positive");
        } else if (number < 0) {
            puts("Negative");
        } else {
            puts("Zero");
        }
        break;
    case 2:
        if (!read_int("Number: ", INT_MIN, INT_MAX, &number)) {
            return 1;
        }
        if (number % 2 == 0) {
            puts("Even");
        } else {
            puts("Odd");
        }
        break;
    case 3:
        if (!read_int("First number: ", INT_MIN, INT_MAX, &a) ||
            !read_int("Second number: ", INT_MIN, INT_MAX, &b) ||
            !read_int("Third number: ", INT_MIN, INT_MAX, &c)) {
            return 1;
        }
        if (a >= b && a >= c) {
            printf("Largest = %d\n", a);
        } else if (b >= c) {
            printf("Largest = %d\n", b);
        } else {
            printf("Largest = %d\n", c);
        }
        break;
    case 4: {
        double x, y, answer;
        char op[8];
        if (!read_double("First number: ", -1e100, 1e100, &x) ||
            !read_line("Operator (+ - * /): ", op, sizeof op) ||
            !read_double("Second number: ", -1e100, 1e100, &y)) {
            return 1;
        }
        if (op[0] == '\0' || op[1] != '\0') {
            puts("Enter one operator.");
            return 1;
        }
        switch (op[0]) {
        case '+': answer = x + y; break;
        case '-': answer = x - y; break;
        case '*': answer = x * y; break;
        case '/':
            if (y == 0.0) {
                puts("Cannot divide by zero.");
                return 1;
            }
            /* Check the quotient's range before dividing. */
            if (fabs(y) < 1.0 && fabs(x) / 1e300 > fabs(y)) {
                puts("Result exceeds the calculator's range.");
                return 1;
            }
            answer = x / y;
            break;
        default:
            puts("Unknown operator.");
            return 1;
        }
        printf("Result = %.10g\n", answer);
        break;
    }
    }
    return 0;
}
