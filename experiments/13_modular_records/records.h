#ifndef EMPLOYEE_RECORDS_H
#define EMPLOYEE_RECORDS_H

#define MAX_EMPLOYEES 50

typedef struct {
    int id;
    char name[64];
} Employee;

int find_employee(const Employee employees[], int count, int id);
void print_employee(const Employee *employee);
void sort_employees(Employee employees[], int count);

#endif
