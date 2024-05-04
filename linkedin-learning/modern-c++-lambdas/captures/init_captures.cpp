// (sort of) Source: https://www.linkedin.com/learning/modern-c-plus-plus-lambdas/init-captures
#include <iostream>
#include <memory>

struct Data {
    void print() {
        std::cout << "Data\n";
    }
};

auto foo_1() {
    std::unique_ptr<Data> p_data(new Data);
    auto y = [p_data = std::move(p_data)]() {
        p_data.get()->print();
    };
    return y;
}

template <typename T>
auto foo_2(T&& t) {
    auto y = [my_t = std::forward<T>(t)]() {
        std::cout << my_t << "\n";
    };
    return y;
}

void exampleA() {
    auto bar = foo_1();
    bar();
}

void exampleB() {
    int n = 1;
    auto l1 = [x1 = n]() {};   // init-capture by copy
    auto l2 = [&x2 = n]() {};  // init-capture by reference

    int m = 3;
    auto l3 = [x3 = n * m + 1]() {};  // (complex) init-capture by value
}

void exampleC() {
    std::string x = "very long string";
    int n = 1;
    auto y = [&, s = std::move(x)]() {
        n++;  // i captured by reference
        std::cout << s << std::endl;
    };
}

void exampleD() {
    std::string a = "another string";
    auto lambda = [&x = std::as_const(a)]() {
        // x = "b";                 // error, x is a read-only reference
        std::cout << x << "\n";  // OK, not modifying x
    };
}

int main() {
    exampleA();
    exampleB();
    exampleC();
    exampleD();

    return 0;
}
