// Source: https://www.linkedin.com/learning/modern-c-plus-plus-lambdas/closure-type-and-closure-objects

#include <type_traits>

int main() {
    auto l1 = [](int a, int b) { return a < b; };
    auto l2 = [](int a, int b) { return a < b; };

    static_assert(!std::is_same<decltype(l1), decltype(l2)>::value);
}
