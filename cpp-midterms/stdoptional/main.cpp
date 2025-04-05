#include <iostream>
#include "optional.hpp"

int main() {
    Optional<int> opt;

    if (!opt.hasValue()) {
        std::cout << "No value set.\n";
    }

    opt.setValue(42);

    if (opt.hasValue()) {
        std::cout << "Value set: " << opt.getValue() << "\n";
    }

    opt.reset();

    if (!opt.hasValue()) {
        std::cout << "Value reset.\n";
    }

    return 0;
}
