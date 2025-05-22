#include <array>
#include <functional>
#include "database.hpp"

void add_objs(Database& database) {
    int type = -1;
    
    do {
        std::cout << "Types: 0 for cat | 1 for snake\n"
                  << "Enter your animal type: ";
        
        std::cin >> type;
        if(type < 0 || type > 1) {
            std::cout << "Invalid option! Try again!\n";
        }
    } while(type < 0 || type > 1);

    database.add_obj(static_cast<AnimalType>(type));
}

void display_obj_by_name(Database& database) {
    std::cout << "Enter name: ";

    std::string name_buff = "";
    std::cin >> name_buff;

    database.display_objs(name_buff);
}

void display_obj_by_type(Database& database) {
    int type = -1;
    
    do {    
        std::cout << "Types: 0 for cat | 1 for snake\n" 
                  << "Enter type: ";

        std::cin >> type;
        if(type < 0 || type > 1) {
            std::cout << "Invalid option! Try again!\n";
        }
    } while(type < 0 || type > 1);

    std::cout << "display_obj_by_type(): type index = " << type;
    database.display_objs(static_cast<AnimalType>(type));
}

int main() {
    Database database = Database();

    std::array<std::function<void(Database&)>, 5> handlers = {
        add_objs,
        [](Database& database) -> void { database.display_objs(); },
        display_obj_by_name,
        display_obj_by_type,
        [](Database&) -> void { std::cout << "Goodbye!\n"; std::exit(1); }
    };

    while(true) {
        std::cout << "1 - Add animal\n"
                  << "2 - Display all\n"
                  << "3 - Display by name\n"
                  << "4 - Display by type\n"
                  << "5 - Exit\n\n"
                  << "Enter your choice: ";

        int choice = 0;
        std::cin >> choice;

        if(choice < 0 || choice > 5) {
            std::cout << "Invalid option! Try again!\n";
            continue;
        }
    
        handlers.at(choice-1)(database);
        std::cout << "\n\n";
    }
}

