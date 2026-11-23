#include "../input.h"

static void swap(int *first, int *second)
{
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

int main(void)
{
    int a, b;
    if (!read_int("First integer: ", -1000000, 1000000, &a) ||
        !read_int("Second integer: ", -1000000, 1000000, &b)) {
        return 1;
    }
    int *pointer = &a;
    printf("Value of a through its pointer = %d\n", *pointer);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    int values[] = {10, 20, 30};
    int *end = values + sizeof values / sizeof values[0];
    puts("Array through pointer arithmetic:");
    for (int *element = values; element != end; ++element) {
        printf("Offset %td: %d\n", element - values, *element);
    }
    return 0;
}
