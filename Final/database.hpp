#pragma once

#include <memory>
#include <vector>
#include <sstream>
#include <fstream>

#include "cat.hpp"
#include "snake.hpp"
#include "animal.hpp"

class Database {
public:
    Database() = default;

    std::unique_ptr<Animal> create_animal(AnimalType type) const {
        switch(type) {
            case AnimalType::CAT:   return std::make_unique<Cat>();
            case AnimalType::SNAKE: return std::make_unique<Snake>();
        }

        throw std::invalid_argument("Invalid animal type!");
    }
    
    void add_obj(AnimalType type) {
        auto animal = create_animal(type);

        std::cin >> *animal;
        m_animals.push_back(std::move(animal));
    }

    void display_objs() const {
        for(auto&& animal : m_animals) {
            std::cout << *animal;
        }
    }

    void display_objs(const std::string& name) const {
        // NOTE: Honestly, "std::views::filter() | std::views::transform" would look 50x better
        for(auto&& animal : m_animals) {
            if(animal->get_name() == name) {
                std::cout << *animal;
            }
        }
    }

    void display_objs(AnimalType type) const {
        for(auto&& animal : m_animals) {
            if(animal->get_type() == type) {
                std::cout << *animal;
            }
        }
    }

    void save_state(const std::string& path) const {
        std::ofstream output_stream(path);
        if(!output_stream.is_open()) {
            std::cerr << "\nFailure to open " << path << "\n";
            return;
        }

        for(auto&& animal : m_animals) {
            serialize(output_stream, *animal);
        }
    }

    void load_state(const std::string& path) {
        std::ifstream input_stream(path);
        if(!input_stream.is_open()) {
            std::cerr << "\nFailure to open " << path << "\n"; 
            return;
        }

        deserialize(input_stream);
    }

private:
    // NOTE: Could be buffered insteaed of writing each animal
    void serialize(std::ofstream& out, const Animal& animal) const {
        AnimalType type = animal.get_type();    
        int type_index = static_cast<int>(type);
    
        switch(type) {
            case AnimalType::CAT: {
                const Cat& cat = dynamic_cast<const Cat&>(animal);
                out << type_index << " " << cat.get_name() << " " << cat.get_breed() << "\n";
            
                break;
            }
        
            case AnimalType::SNAKE: {
                const Snake& snake = dynamic_cast<const Snake&>(animal);
                out << type_index << " " << snake.get_name() << " " << snake.get_is_venomous() << "\n";
            
                break;
            }
        }
    }

    std::vector<std::string> split(const std::string& str) {        
        std::istringstream ss(str);
        std::vector<std::string> parts;

        std::string part;
        while(ss >> part) {
            parts.push_back(part);
        }

        return parts;
    }
    
    void deserialize(std::ifstream& in) {
        std::string line;
        while(std::getline(in, line)) {
            std::vector<std::string> parsed_line = split(line);

            int type_index = std::stoi(parsed_line.at(0));
            AnimalType type = static_cast<AnimalType>(type_index);
            
            std::unique_ptr<Animal> animal = create_animal(type);
            
            switch(type) {
                case AnimalType::CAT: {
                    Cat& cat = dynamic_cast<Cat&>(*animal);
                    cat.set_name(parsed_line.at(1));
                    cat.set_breed(parsed_line.at(2));

                    m_animals.push_back(std::make_unique<Cat>(cat));
                    
                    break;
                }

                case AnimalType::SNAKE: {
                    Snake& snake = dynamic_cast<Snake&>(*animal);
                    snake.set_name(parsed_line.at(1));
                    snake.set_is_venomous(type_index == 0 ? false : true);

                    m_animals.push_back(std::make_unique<Snake>(snake));
                    
                    break;       
                }
            }
        }
    };
    
    std::vector<std::unique_ptr<Animal>> m_animals;
};

