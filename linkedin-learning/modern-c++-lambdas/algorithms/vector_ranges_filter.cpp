// Source: https://www.linkedin.com/learning/modern-c-plus-plus-lambdas/lambdas-and-standard-library-algorithms

#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : v | std::ranges::views::filter([](int i) { return i % 2; })) {
        std::cout << i << " ";
    }
}
