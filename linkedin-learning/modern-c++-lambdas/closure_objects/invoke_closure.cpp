// Source: https://www.linkedin.com/learning/modern-c-plus-plus-lambdas/closure-type-and-closure-objects

#include <iostream>
#include <type_traits>

int main() {
    auto lambda1 = [](int a, int b) { return a < b; };
    bool b = lambda1(1, 2);

    int i = 2;
    int j = 3;
    if (lambda1(i, j)) {
        std::cout << "'i' is less than j\n";
    }
}
