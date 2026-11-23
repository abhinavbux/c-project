#include <stdio.h>
#include <threads.h>
#include "../input.h"

typedef struct {
    int limit;
    long long result;
} Task;

static int sum_numbers(void *data)
{
    Task *task = data;
    long long sum = 0;
    for (int i = 1; i <= task->limit; ++i) {
        sum += i;
    }
    task->result = sum;
    return 0;
}

static int sum_squares(void *data)
{
    Task *task = data;
    long long sum = 0;
    for (int i = 1; i <= task->limit; ++i) {
        sum += (long long)i * i;
    }
    task->result = sum;
    return 0;
}

int main(void)
{
    int n;
    if (!read_int("Sum from 1 to n (1-100000): ", 1, 100000, &n)) {
        return 1;
    }
    Task numbers = {n, 0};
    Task squares = {n, 0};
    thrd_t number_thread, square_thread;

    if (thrd_create(&number_thread, sum_numbers, &numbers) != thrd_success) {
        puts("Could not create the number worker.");
        return 1;
    }
    if (thrd_create(&square_thread, sum_squares, &squares) != thrd_success) {
        (void)thrd_join(number_thread, NULL);
        puts("Could not create the square worker.");
        return 1;
    }

    int number_join = thrd_join(number_thread, NULL);
    int square_join = thrd_join(square_thread, NULL);
    if (number_join != thrd_success || square_join != thrd_success) {
        puts("Could not join both workers.");
        return 1;
    }
    printf("Worker 1 sum: %lld\n", numbers.result);
    printf("Worker 2 sum of squares: %lld\n", squares.result);
    return 0;
}
