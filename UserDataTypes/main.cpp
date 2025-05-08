#include "employee.h"


int main() {
    int n_employees = 0;
    std::cout << "Number of employees: ";
    std::cin >> n_employees;

    n_employees = n_employees <= 5 ? n_employees : 5;

    Employee employees[5] = {};
    for(int i = 0; i < n_employees; ++i) {
        std::cout << "Enter details for employee " << i + 1 << ": \n";
        employees[i].read();
    }

    for(int i = 0; i < n_employees; ++i) {
        employees[i].write();
    }
}

