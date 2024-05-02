// (sort of) Source: https://www.linkedin.com/learning/modern-c-plus-plus-lambdas/lambda-capture
#include <iostream>

void print_bool(char* name, bool v) {
    std::cout << name << ": " << v << '\n';
}

int main() {
    std::cout << std::boolalpha;

    // capture 'n' as copy
    int n = 6;
    auto equal_n = [n](int i) { return i == n; };
    n = 3;
    bool is_equal_n = equal_n(3);
    print_bool("is_equal_n", is_equal_n);

    // capture 'j' by reference
    int j = 10;
    auto equal_j = [&j](int i) { return i == j; };
    j = 15;
    bool is_equal_j = equal_j(15);
    print_bool("is_equal_j", is_equal_j);

    // capture all as copy
    auto between_n_j = [=](int i) { return i >= n && i <= j; };
    n = 10;
    j = 20;
    bool is_between_n_j = between_n_j(5);
    print_bool("is_between_n_j", is_between_n_j);

    // capture all by reference
    int i = 1;
    char c = 'c';
    auto print_c_i_times = [&]() {
        for (int k = 0; k < i; ++k) {
            std::cout << c;
        }
        std::cout << std::endl;
    };
    i = 5;
    c = 'a';
    print_c_i_times();

    return 0;
}
