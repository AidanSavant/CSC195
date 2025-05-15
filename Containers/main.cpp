#include <map>
#include <list>
#include <array>
#include <vector>
#include <iostream>

int main() {
    /* == Array section == */

    // Inserting days
    std::array<std::string, 7> days = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    // Printing days
    for(const auto& day : days) {
        std::cout << day << '\n';
    }

    std::cout << "\n\n";

    /* == Vector section == */

    // Inserting ints
    std::vector<int> ints = {
        1, 2, 3, 4, 5  
    };

    // Adding two elements and removing one element
    ints.push_back(6);
    ints.push_back(7);
    ints.pop_back();

    // Printing resulting ints
    for(const auto& int_v : ints) {
        std::cout << int_v << '\n';
    }

    std::cout << "\n\n";

    /* == List section == */

    // Inserting fruits
    std::list<std::string> fruits = {
        "Strawberry", "Apple", "Banana"
    };

    // Pushing a fruit to the head and the tail of the list
    fruits.push_back("Apricot");
    fruits.push_front("Orange");

    // Removing head value
    fruits.remove("Orange");

    // Printing elements using an iterator
    for(auto i = fruits.begin(); i != fruits.end(); i++) {
        std::cout << *i << '\n';
    }

    std::cout << "\n\n";

    /* == Ordered map section == */

    // Inserting product -> # in stock pairs
    std::map<std::string, int> map = {
        std::make_pair("Apples", 10),
        std::make_pair("Bananas", 5),
        std::make_pair("Oranges", 1)
    };

    // Update oranges key
    map["Oranges"] = 15;

    // Printing each key-value pair using structured bindings
    for(const auto& [key, value] : map) {
        std::cout << key << " : " << value << '\n';
    }
}

