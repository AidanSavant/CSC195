#include <iostream>

void swap(int& x, int& y) {
    int x_temp = x;
    x = y;
    y = x_temp;  
}

int main() {
    int x = 10;
    int y = 20;

    std::cout << x << ',' << y << '\n';

    swap(x, y);

    std::cout << x << ',' << y << '\n';
}

