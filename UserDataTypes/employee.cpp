#include "employee.h"

const float Employee::TAX = 0.1f;

void Employee::read() {
    std::cout << "Enter name: ";
    std::cin >> m_name;

    std::cout << "Enter age: ";
    std::cin >> m_age;

    std::cout << "Enter zipcode: ";
    std::cin >> m_zipcode;

    std::cout << "Enter hourly wage: ";
    std::cin >> m_wage;

    std::cout << "Enter total hours worked this week: ";
    std::cin >> m_hours_worked;
}

void Employee::write() {
    float weeklyGross = m_wage * m_hours_worked;
    float weeklyTax = weeklyGross * TAX;
    float weeklyNet = weeklyGross - weeklyTax;
    float yearlyGross = weeklyGross * 52;
    float yearlyNet = yearlyGross - (yearlyGross * TAX);

    std::cout << "\nEmployee Payroll Summary\n";
    std::cout << "-------------------------\n";
    std::cout << "Name: " << m_name << "\n";
    std::cout << "Age: " << m_age << "\n";
    std::cout << "Zipcode: " << m_zipcode << "\n";
    std::cout << "Hourly Wage: $" << m_wage << "\n";
    std::cout << "Hours Worked: " << m_hours_worked << "\n";
    std::cout << "Weekly Gross Pay: $" << weeklyGross << "\n";
    std::cout << "Weekly Net Pay: $" << weeklyNet << "\n";
    std::cout << "Yearly Gross Pay: $" << yearlyGross << "\n";
    std::cout << "Yearly Net Pay: $" << yearlyNet << "\n";
}

