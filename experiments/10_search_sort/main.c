#include "../input.h"

int main(void)
{
    int values[100], count, target;
    if (!read_int("Number of elements (1-100): ", 1, 100, &count)) {
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        if (!read_int("Enter an element: ", -1000000, 1000000, &values[i])) {
            return 1;
        }
    }
    if (!read_int("Value to find: ", -1000000, 1000000, &target)) {
        return 1;
    }

    int original_index = -1;
    for (int i = 0; i < count; ++i) {
        if (values[i] == target) {
            original_index = i;
            break;
        }
    }

    for (int end = count - 1; end > 0; --end) {
        int swapped = 0;
        for (int i = 0; i < end; ++i) {
            if (values[i] > values[i + 1]) {
                int temporary = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temporary;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }

    int first = 0, past_last = count;
    while (first < past_last) {
        int middle = first + (past_last - first) / 2;
        if (values[middle] < target) {
            first = middle + 1;
        } else {
            past_last = middle;
        }
    }
    int sorted_index = first < count && values[first] == target ? first : -1;

    printf("Sorted:");
    for (int i = 0; i < count; ++i) {
        printf(" %d", values[i]);
    }
    printf("\nLinear search in original array: index %d\n", original_index);
    printf("Binary search in sorted array: index %d\n", sorted_index);
    puts("Indexes start at 0. Index -1 means the value was not found.");
    return 0;
}
