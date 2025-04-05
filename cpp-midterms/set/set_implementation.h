#ifndef SET_IMPLEMENTATION_H
#define SET_IMPLEMENTATION_H

#include <set>
#include <iostream>

class Set {
private:
    std::set<int> data;

public:
    void insert(int value);
    void remove(int value);
    void display() const;
    bool contains(int value) const; // Check if an element exists
    size_t size() const;           // Get the size of the set
    void clear();                  // Clear all elements
    int getMin() const;            // Get the smallest element
    int getMax() const;            // Get the largest element
    bool isEmpty() const;          // Check if the set is empty
};

#endif // SET_IMPLEMENTATION_H
