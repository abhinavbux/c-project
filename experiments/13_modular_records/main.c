#include "../input.h"
#include "records.h"

int main(void)
{
    Employee employees[MAX_EMPLOYEES];
    int count = 0;

    for (;;) {
        int choice;
        puts("\n1. Add\n2. Display\n3. Search by ID\n4. Sort by ID\n5. Exit");
        if (!read_int("Choose an option: ", 1, 5, &choice)) {
            return 1;
        }
        switch (choice) {
        case 1: {
            Employee employee;
            if (count == MAX_EMPLOYEES) {
                puts("Employee list is full.");
                break;
            }
            if (!read_int("Employee ID: ", 1, 1000000, &employee.id)) {
                return 1;
            }
            if (find_employee(employees, count, employee.id) >= 0) {
                puts("That ID already exists.");
                break;
            }
            if (!read_line("Full name: ", employee.name, sizeof employee.name)) {
                return 1;
            }
            if (at_end(employee.name)) {
                puts("A name is required.");
                break;
            }
            employees[count++] = employee;
            puts("Employee added.");
            break;
        }
        case 2:
            if (count == 0) {
                puts("No employees yet.");
            }
            for (int i = 0; i < count; ++i) {
                print_employee(&employees[i]);
            }
            break;
        case 3: {
            int id;
            if (!read_int("ID to find: ", 1, 1000000, &id)) {
                return 1;
            }
            int index = find_employee(employees, count, id);
            if (index < 0) {
                puts("Employee not found.");
            } else {
                puts("Employee found:");
                print_employee(&employees[index]);
            }
            break;
        }
        case 4:
            sort_employees(employees, count);
            puts("Sorted by ID.");
            break;
        case 5:
            return 0;
        }
    }
}
