#pragma once

#include <iostream>
#include <string>

class Employee {
public:
    void read();
    void write();      

private:
    std::string m_name;
    short m_age;
    unsigned int m_zipcode;
    float m_wage;
    float m_hours_worked;

    static const float TAX;
};

