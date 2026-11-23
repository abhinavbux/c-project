#include <stdio.h>
#include "records.h"

int find_employee(const Employee employees[], int count, int id)
{
    for (int i = 0; i < count; ++i) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void print_employee(const Employee *employee)
{
    printf("%d | %s\n", employee->id, employee->name);
}

void sort_employees(Employee employees[], int count)
{
    for (int i = 1; i < count; ++i) {
        Employee current = employees[i];
        int position = i;
        while (position > 0 && employees[position - 1].id > current.id) {
            employees[position] = employees[position - 1];
            --position;
        }
        employees[position] = current;
    }
}
