// Source: https://www.linkedin.com/learning/modern-c-plus-plus-lambdas/what-is-a-lambda

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{3, 6, 2, 5, 4};
    long sum = 0;
    std::for_each(v.cbegin(), v.cend(), [&sum](int n){sum+=n;});

    std::cout << "The sum is: " << sum << std::endl;

    return 0;
}
