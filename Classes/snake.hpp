#pragma once

#include <cctype>
#include <algorithm>

#include "animal.hpp"

class Snake : public Animal {
public:
    Snake() = default;
    
    void speak() override {
        std::cout << "ssssssssss" << '\n';
    }

    void walk() override {
        std::cout << "Slither slither slither" << '\n';
    }

    AnimalType get_type() override {
        return AnimalType::SNAKE;
    }

    void read(std::ostream& ostream, std::istream& istream) override {
        Animal::read(ostream, istream);

        std::string temp_buff;
        std::cout << "Is the snake venomous (yes or no): ";
        istream >> temp_buff;

        // C++ doesn't have a built-in tolower function...
        auto to_lower = [](unsigned char c){ return std::tolower(c); };
        std::transform(temp_buff.begin(), temp_buff.end(), temp_buff.begin(), to_lower);
    
        m_is_venomous = temp_buff == "yes" ? true : false;
    }

    void write(std::ostream& ostream) override {
        Animal::write(ostream);
        std::cout << "\033[0;34mis_venomous: " << (m_is_venomous ? "yes" : "no") << "\033[0m\n";
    }

private:
    bool m_is_venomous;
};

