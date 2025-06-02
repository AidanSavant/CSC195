#pragma once

#include <cctype>
#include <algorithm>

#include "animal.hpp"

class Snake : public Animal {
public:
    Snake() = default;
    
    AnimalType get_type() const override {
        return AnimalType::SNAKE;
    }

    bool get_is_venomous() const { return m_is_venomous; }
    void set_is_venomous(bool is_venonmous) { m_is_venomous = is_venonmous; }

    std::istream& input(std::istream& in) override {
        std::string name_buff;
        std::cout << "Enter name: ";
        in >> name_buff;

        set_name(name_buff);
        
        std::string venomous_buff;
        std::cout << "Is the snake venomous (yes or no): ";
        in >> venomous_buff;

        // C++ doesn't have a built-in tolower function...
        auto to_lower = [](unsigned char c){ return std::tolower(c); };
        std::transform(venomous_buff.begin(), venomous_buff.end(), venomous_buff.begin(), to_lower);
    
        set_is_venomous(venomous_buff == "yes" ? true : false);

        return in;
    }

    std::ostream& output(std::ostream& out) const override {
        out << "\n\033[0;34mName: " << get_name() << "\n"
            << "Animal Type: "      << type_to_string(get_type()) << "\n"
            << "is_venomous: "      << (get_is_venomous() ? "yes" : "no") << "\033[0m\n";
    
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Snake& snake) { snake.input(in); return in; }
    friend std::ostream& operator<<(std::ostream& out, const Snake& snake) { snake.output(out); return out; }

private:
    bool m_is_venomous;
};

