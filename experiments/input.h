#ifndef LAB_INPUT_H
#define LAB_INPUT_H

#include <errno.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Read one complete line. Reject a line that does not fit the buffer. */
static inline int read_line(const char *prompt, char *buffer, int capacity)
{
    printf("%s", prompt);
    fflush(stdout);
    if (!fgets(buffer, capacity, stdin)) {
        return 0;
    }

    int length = 0;
    while (buffer[length] && buffer[length] != '\n') {
        ++length;
    }
    if (buffer[length] == '\n') {
        buffer[length] = '\0';
        return 1;
    }
    int next = getchar();
    if (next == '\n' || next == EOF) {
        return 1;
    }
    while ((next = getchar()) != '\n' && next != EOF) {
    }
    puts("Input is too long.");
    return 0;
}

static inline int at_end(const char *text)
{
    while (isspace((unsigned char)*text)) {
        ++text;
    }
    return *text == '\0';
}

static inline int read_int(const char *prompt, int min, int max, int *result)
{
    char line[128], *end;
    if (!read_line(prompt, line, sizeof line)) {
        return 0;
    }
    errno = 0;
    long value = strtol(line, &end, 10);
    if (end == line || !at_end(end) || errno == ERANGE || value < min || value > max) {
        printf("Enter a whole number from %d to %d.\n", min, max);
        return 0;
    }
    *result = (int)value;
    return 1;
}

static inline int read_double(const char *prompt, double min, double max, double *result)
{
    char line[128], *end;
    if (!read_line(prompt, line, sizeof line)) {
        return 0;
    }
    errno = 0;
    double value = strtod(line, &end);
    if (end == line || !at_end(end) || errno == ERANGE || !isfinite(value) ||
        value < min || value > max) {
        printf("Enter a decimal number from %g to %g.\n", min, max);
        return 0;
    }
    *result = value;
    return 1;
}

#endif
