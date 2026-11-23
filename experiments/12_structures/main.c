#include "../input.h"

#define MAX_STUDENTS 20

typedef struct {
    int roll_number;
    char name[64];
    double marks;
} Student;

int main(void)
{
    Student students[MAX_STUDENTS];
    int count;
    if (!read_int("Number of students (1-20): ", 1, MAX_STUDENTS, &count)) {
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        printf("Student %d\n", i + 1);
        if (!read_int("Roll number: ", 1, 1000000, &students[i].roll_number)) {
            return 1;
        }
        for (int j = 0; j < i; ++j) {
            if (students[j].roll_number == students[i].roll_number) {
                puts("Roll numbers must be unique.");
                return 1;
            }
        }
        if (!read_line("Full name: ", students[i].name, sizeof students[i].name)) {
            return 1;
        }
        if (at_end(students[i].name)) {
            puts("A name is required.");
            return 1;
        }
        if (!read_double("Marks (0-100): ", 0, 100, &students[i].marks)) {
            return 1;
        }
    }

    puts("All students:");
    for (int i = 0; i < count; ++i) {
        printf("%d | %s | %.2f\n", students[i].roll_number, students[i].name,
               students[i].marks);
    }

    int target;
    if (!read_int("Roll number to find: ", 1, 1000000, &target)) {
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        if (students[i].roll_number == target) {
            printf("Found: %d | %s | %.2f\n", students[i].roll_number,
                   students[i].name, students[i].marks);
            return 0;
        }
    }
    puts("Student not found.");
    return 0;
}
