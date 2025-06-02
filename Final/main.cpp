#include <limits>
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

std::string read_path(const std::string& prompt) {
    std::string path_buff = "";

    std::cout << prompt;
    std::cin >> path_buff;

    return path_buff;
}

void save_db_state(const Database& database) {
    database.save_state(read_path("Enter your save path: "));    
}

void load_db_state(Database& database) {
    database.load_state(read_path("Enter load path: "));    
}

int main() {
    Database database = Database();

    while(true) {
        std::cout << "1 - Add animal\n"
                  << "2 - Display all\n"
                  << "3 - Display by name\n"
                  << "4 - Display by type\n"
                  << "5 - Save\n"
                  << "6 - Load\n"
                  << "7 - Exit\n\n"
                  << "Enter your choice: ";

        int choice = 0;
        if (!(std::cin >> choice)) {
            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input! Please enter a number.\n\n";
            continue;
        }

        switch(choice) {
            case 1: add_objs(database);            break;
            case 2: database.display_objs();       break;
            case 3: display_obj_by_name(database); break;
            case 4: display_obj_by_type(database); break;
            case 5: save_db_state(database);       break;
            case 6: load_db_state(database);       break;
            case 7: std::cout << "Goodbye!\n";     return 0;
                
            default: std::cerr << "Invalid choice! Try again!\n";
        }
        
        std::cout << "\n\n";
    }
}

