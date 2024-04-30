// Source: https://www.linkedin.com/learning/modern-c-plus-plus-lambdas/lambdas-and-standard-library-algorithms

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector v{4, 1, 3, 2};

    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

    std::for_each(v.cbegin(), v.cend(), [](int i) { std::cout << i << " "; });
}
