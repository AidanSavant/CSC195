#pragma once

#include <string>
#include <iostream>

enum class AnimalType {
    CAT, SNAKE   
};

class Animal {
public:
    Animal() = default;
    virtual ~Animal() = default;


    std::string get_name() const { return m_name; }
    void set_name(const std::string& name) { m_name = name; }
    
    virtual AnimalType get_type() const = 0;

    // NOTE: Polymorphic implementations
    virtual std::istream& input(std::istream& is) = 0;
    virtual std::ostream& output(std::ostream& os) const = 0;

    friend std::istream& operator>>(std::istream& in, Animal& animal) {
        return animal.input(in);
    }

    friend std::ostream& operator<<(std::ostream& out, const Animal& animal) {
        return animal.output(out);
    }

    // NOTE: Should really return a std::string_view, but I think this course is C++14 and string_view is C++17
    static const char *type_to_string(AnimalType type) {
        switch(type) {
            case AnimalType::CAT:   return "Cat";
            case AnimalType::SNAKE: return "Snake";
            default:                return "Unknown animal type";
        }
    }

protected:
    std::string m_name;
};

