#pragma once

#include <iostream>

enum class AnimalType {
    CAT, SNAKE, LEN   
};

class Animal {
public:
    Animal() = default;
    virtual ~Animal() = default;
    
    Animal(const std::string& name) : m_name(name) 
    {}

    std::string get_name() { return m_name; }
    virtual AnimalType get_type() = 0;

    virtual void speak() {
        std::cout << "Animal speaks";
    }
    
    virtual void walk() {
        std::cout << "Animal walks";
    }

    virtual void read(std::ostream& ostream, std::istream& istream) {
        ostream << "Enter name: ";
        istream >> m_name;
    }

    virtual void write(std::ostream& ostream) {         
        ostream << "\n\033[0;34mName: " << m_name << "\n"
                << "Animal Type: "      << Animal::type_to_string(get_type()) << "\033[0m\n";
    }

    // NOTE: Should really return a std::string_view, but I think this course is C++14 and string_view is C++17
    static const char *type_to_string(AnimalType type) {
        switch(type) {
            case AnimalType::CAT:   return "Cat";
            case AnimalType::SNAKE: return "Snake";
            default: return "Unknown";
        }
    }

private:
    std::string m_name;
};

