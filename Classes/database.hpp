#pragma once

#include <cstdlib>
#include <memory>
#include <vector>

#include "cat.hpp"
#include "snake.hpp"
#include "animal.hpp"

class Database {
public:
    Database() = default;

    void add_obj(AnimalType type) {
        switch(type) {
            case AnimalType::CAT: {
                Cat cat = Cat();
                cat.read(std::cout, std::cin);

                animals.push_back(std::make_unique<Cat>(cat));

                break;
            }

            case AnimalType::SNAKE: {
                Snake snake = Snake();
                snake.read(std::cout, std::cin);

                animals.push_back(std::make_unique<Snake>(snake));
                
                break;       
            }

            default: std::cerr << "Invaild animal type!\n"; std::exit(1);
        }
    }

    void display_objs() {
        for(auto&& animal : animals) {
            animal->write(std::cout);
        }
    }

    void display_objs(const std::string& name) {
        // NOTE: Honestly, "std::views::filter() | std::views::transform" would look 50x better
        for(auto&& animal : animals) {
            if(animal->get_name() == name) {
                animal->write(std::cout);
            }
        }
    }

    void display_objs(AnimalType type) {        
        for(auto&& animal : animals) {
            if(animal->get_type() == type) {
                animal->write(std::cout);
            }
        }
    }

private:
    std::vector<std::unique_ptr<Animal>> animals;
};

