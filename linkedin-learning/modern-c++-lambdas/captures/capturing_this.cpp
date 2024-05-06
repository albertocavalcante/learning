// (sort of) Source: https://www.linkedin.com/learning/modern-c-plus-plus-lambdas/capturing-this
#include <iostream>

struct S {
    void memberFunc() {
    }

    void callLambda_1() {
        [&]() {
            memberFunc();  // OK, implicitly captures `this` pointer
        }();
    }

    void callLambda_2() {
        [this]() {
            memberFunc();  // OK, explicitly captures `this` pointer
        }();
    }
};

struct T {
    int i;
    char c;

    auto getLambda_1() {
        return [this]() {  // capture `this` pointer
            std::cout << i;
        }();
    }

    auto getLambda_2() {
        return [*this]() {  // capture `*this` object by copy
            std::cout << i;
        }();
    }

    auto getLambda_3() {
        return [myI = i]() {
            std::cout << myI;  // OK
        }();
    }
};
