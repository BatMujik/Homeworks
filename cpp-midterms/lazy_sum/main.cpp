#include <iostream>
#include <vector>
#include "lazy_sum.hpp"

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = {5, 6, 7, 8};

    auto lazySum = make_lazy_sum(vec1, vec2);

    std::cout << "Lazy sum of containers:" << std::endl;
    for (size_t i = 0; i < lazySum.size(); ++i) {
        std::cout << "Index " << i << ": " << lazySum[i] << std::endl;
    }

    return 0;
}
