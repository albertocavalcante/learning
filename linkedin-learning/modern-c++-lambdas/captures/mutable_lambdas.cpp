#include <iostream>

int main() {
    int i = 4;

    auto l = [i]() mutable{
        std::cout << i++; // OK, without 'mutable' it would error
    };
}
