#include "../input.h"

int main(void)
{
    int number;
    if (!read_int("Enter an integer: ", -999999999, 999999999, &number)) {
        return 1;
    }

    int magnitude = number < 0 ? -number : number;
    int remaining = magnitude;
    int reverse = 0, sum = 0;
    do {
        int digit = remaining % 10;
        reverse = reverse * 10 + digit;
        sum += digit;
        remaining /= 10;
    } while (remaining != 0);

    printf("Reverse = %d\n", number < 0 ? -reverse : reverse);
    printf("Digit sum = %d\n", sum);
    printf("Palindrome: %s\n", number >= 0 && reverse == number ? "yes" : "no");

    int prime = number >= 2;
    for (int divisor = 2; prime && divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {
            prime = 0;
        }
    }
    printf("Prime: %s\n", prime ? "yes" : "no");
    return 0;
}
