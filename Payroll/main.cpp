#include <iostream>

int main() {
    const float TAX = 0.1f;

    std::string name = "";
    std::cout << "Enter first name: ";
    std::cin >> name;

    char initial = ' ';
    std::cout << "Enter last initial: ";
    std::cin >> initial;

    int age = 0;
    std::cout << "Enter age: ";
    std::cin >> age;

    bool is_adult = age >= 18;

    unsigned int zip_code = 0;
    std::cout << "Enter zip code: ";
    std::cin >> zip_code;

    float wage = 0;
    std::cout << "Enter hourly wage: ";
    std::cin >> wage;

    short days_worked = 0;
    std::cout << "Enter number of days worked (max 7): ";
    std::cin >> days_worked;

    float hours_worked_pday[7] = { 0 };
    int total_hours_worked = 0;
    for (int i = 0; i < days_worked; ++i) {
    	std::cout << "Enter hours worked for day " << i + 1 << ": ";
    	std::cin >> hours_worked_pday[i];

    	total_hours_worked += hours_worked_pday[i];
    }

    float grossIncome = total_hours_worked * wage;
    float taxAmount = grossIncome * TAX;
    float netIncome = grossIncome - taxAmount;

    std::cout << "\nEmployee Payroll Summary\n";
    std::cout << "-------------------------\n";
    std::cout << "Name: " << name << " " << initial << ".\n";
    std::cout << "Age: " << age << " (Adult: " << (is_adult ? "Yes" : "No") << ")\n";
    std::cout << "Zipcode: " << zip_code << "\n";
    std::cout << "Hourly Wage: $" << wage << " per hour\n";
    std::cout << "Total Hours Worked: " << total_hours_worked << " hours\n";
    std::cout << "Gross Income: $" << grossIncome << "\n";
    std::cout << "Tax Amount: $" << taxAmount << "\n";
    std::cout << "Net Income: $" << netIncome << "\n";
}

