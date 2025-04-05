#include "set_implementation.h"

int main() {
    Set mySet;

    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);

    std::cout << "Set after insertion: ";
    mySet.display();

    std::cout << "Set contains 20: " << (mySet.contains(20) ? "Yes" : "No") << std::endl;
    std::cout << "Set size: " << mySet.size() << std::endl;
    std::cout << "Minimum element: " << mySet.getMin() << std::endl;
    std::cout << "Maximum element: " << mySet.getMax() << std::endl;

    mySet.remove(20);
    std::cout << "Set after removal of 20: ";
    mySet.display();

    mySet.clear();
    std::cout << "Set after clearing: ";
    mySet.display();
    std::cout << "Set size: " << mySet.size() << std::endl;
    std::cout << "Is set empty: " << (mySet.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
