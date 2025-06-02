#pragma once

#include "animal.hpp"

class Cat : public Animal {
public:
    Cat() = default;

    std::string get_breed() const { return m_breed; }
    void set_breed(const std::string& breed) { m_breed = breed; }

    AnimalType get_type() const override {
        return AnimalType::CAT;
    }

    std::istream& input(std::istream& in) override {
        std::string name_buff;
        std::cout << "Enter name: ";
        in >> name_buff;

        set_name(name_buff);

        std::string breed_buff;
        std::cout << "Enter your breed: ";
        in >> breed_buff;

        set_breed(breed_buff);
        
        return in;
    } 
    
    std::ostream& output(std::ostream& out) const override {
        out << "\n\033[0;34mName: " << get_name() << "\n"
           << "Animal Type: "       << type_to_string(get_type()) << "\n"
           << "Breed: "             << get_breed() << "\033[0m\n";
        
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Cat& cat) { cat.input(in); return in; }
    friend std::ostream& operator<<(std::ostream& out, const Cat& cat) { cat.output(out); return out; }
    
private:
    std::string m_breed;
};

