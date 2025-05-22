#pragma once

#include "animal.hpp"

class Cat : public Animal {
public:
    Cat() = default;
    
    std::string get_breed() { return m_breed; }

    void speak() override {
        std::cout << "Meow meow meow" << '\n';
    }

    void walk() override {
        std::cout << "Thump thump thump" << '\n';
    }

    AnimalType get_type() override {
        return AnimalType::CAT;
    }

    void read(std::ostream& ostream, std::istream& istream) override {
        Animal::read(ostream, istream);
        ostream << "Enter your breed: ";
        istream >> m_breed;
    }

    void write(std::ostream& ostream) override {
        Animal::write(ostream);
        ostream << "\033[0;34mBreed: " << m_breed << "\033[0m\n";
    }
    
private:
    std::string m_breed;
};

