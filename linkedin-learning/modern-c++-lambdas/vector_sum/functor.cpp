// Source: https://www.linkedin.com/learning/modern-c-plus-plus-lambdas/what-is-a-lambda

#include <algorithm>
#include <iostream>
#include <vector>

struct SumFunctor {
    long sum = 0;
    SumFunctor(long init) : sum(init){};
    void operator()(int n) {
        sum += n;
    }
};

int main() {
    std::vector<int> v{3, 6, 2, 5, 4};
    SumFunctor s(0);
    std::for_each(v.cbegin(), v.cend(), std::ref(s));

    std::cout << "The sum is: " << s.sum << std::endl;

    return 0;
}
