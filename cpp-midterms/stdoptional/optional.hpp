#pragma once
#include <utility>
#include <stdexcept>

template <typename T>
class Optional {
private:
    bool has_value;
    T value;

public:
    Optional() : has_value(false) {}
    Optional(const T& val) : has_value(true), value(val) {}
    Optional(T&& val) : has_value(true), value(std::move(val)) {}

    bool hasValue() const { return has_value; }

    T& getValue() {
        if (!has_value) {
            throw std::runtime_error("No value present");
        }
        return value;
    }

    const T& getValue() const {
        if (!has_value) {
            throw std::runtime_error("No value present");
        }
        return value;
    }

    void reset() { has_value = false; }

    void setValue(const T& val) {
        value = val;
        has_value = true;
    }

    void setValue(T&& val) {
        value = std::move(val);
        has_value = true;
    }
};
