#include "fraction.hpp"

using mathlib::Fraction;

int main() {
    Fraction fraction1{ 15, 5 };
    std::cout << fraction1 << std::endl;

    Fraction fraction2{ 15, 6 };
    fraction2.simplify();
    std::cout << fraction2 << std::endl;
    
    std::cout << fraction1 << " == " << fraction2 << " result: " << std::boolalpha << (fraction1 == fraction2) << std::endl;
    std::cout << fraction1 << " > " << fraction2 << " result: " << (fraction1 > fraction2) << std::endl;

    std::cout << fraction1 << " + " << fraction2 << " result: " << (fraction1 + fraction2) << std::endl;
    std::cout << fraction1 << " * " << fraction2 << " result: " << (fraction1 * fraction2) << std::endl;

    Fraction<int> fraction3;
    std::cout << "input fraction (numerator '-' or '/' denominator): \n";
    std::cin >> fraction3;
    std::cout << fraction3 << std::endl;
    std::cout << fraction3.to_double() << std::endl;
}

