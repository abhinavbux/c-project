#include "../input.h"

int main(void)
{
    int values[100], count;
    if (!read_int("Number of elements (1-100): ", 1, 100, &count)) {
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        if (!read_int("Enter an element: ", -1000000, 1000000, &values[i])) {
            return 1;
        }
    }
    long long sum = 0;
    int minimum = values[0], maximum = values[0];
    for (int i = 0; i < count; ++i) {
        sum += values[i];
        if (values[i] < minimum) {
            minimum = values[i];
        }
        if (values[i] > maximum) {
            maximum = values[i];
        }
    }
    printf("Sum = %lld\nAverage = %.2f\nMinimum = %d\nMaximum = %d\n",
           sum, (double)sum / count, minimum, maximum);

    for (int left = 0, right = count - 1; left < right; ++left, --right) {
        int temporary = values[left];
        values[left] = values[right];
        values[right] = temporary;
    }
    printf("Reversed:");
    for (int i = 0; i < count; ++i) {
        printf(" %d", values[i]);
    }
    putchar('\n');
    return 0;
}
