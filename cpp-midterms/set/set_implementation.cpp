#include "set_implementation.h"

void Set::insert(int value) {
    data.insert(value);
}

void Set::remove(int value) {
    data.erase(value);
}

void Set::display() const {
    for (const int& value : data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

bool Set::contains(int value) const {
    return data.find(value) != data.end();
}

size_t Set::size() const {
    return data.size();
}

void Set::clear() {
    data.clear();
}

int Set::getMin() const {
    return data.empty() ? throw std::runtime_error("Set is empty") : *data.begin();
}

int Set::getMax() const {
    return data.empty() ? throw std::runtime_error("Set is empty") : *data.rbegin();
}

bool Set::isEmpty() const {
    return data.empty();
}
