// Source: https://www.linkedin.com/learning/modern-c-plus-plus-lambdas/closure-type-and-closure-objects

#include <type_traits>

int main() {
    auto l1 = [](int a, int b) { return a < b; };
    auto l2 = [](int a, int b) { return a < b; };

    // Note: since C++ 17 it's possible to use std::is_same_v
    static_assert(!std::is_same<decltype(l1), decltype(l2)>::value);
}
