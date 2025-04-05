#ifndef LAZY_SUM_HPP
#define LAZY_SUM_HPP

#include <vector>
#include <stdexcept>

template <typename Container>
class LazySum
{
private:
    const Container &container1;
    const Container &container2;

public:
    LazySum(const Container &c1, const Container &c2)
        : container1(c1), container2(c2)
    {
        if (container1.size() != container2.size())
        {
            throw std::invalid_argument("Containers must have the same size");
        }
    }

    auto operator[](size_t index) const
    {
        if (index >= container1.size())
        {
            throw std::out_of_range("Index out of range");
        }
        return container1[index] + container2[index];
    }

    size_t size() const
    {
        return container1.size();
    }
};

template <typename Container>
LazySum<Container> make_lazy_sum(const Container &c1, const Container &c2)
{
    return LazySum<Container>(c1, c2);
}

#endif // LAZY_SUM_HPP
