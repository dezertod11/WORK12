#include <iostream>

template <std::size_t n>
struct Fibonachi
{
    static constexpr int value = Fibonachi<n - 1>::value + Fibonachi<n - 2>::value;
};

template <>
struct Fibonachi<1>
{
    static constexpr int value = 1;
};

template <>
struct Fibonachi<2>
{
    static constexpr int value = 1;
};

template <std::size_t n>
static constexpr int Fibonachi_v = Fibonachi<n>::value;

int main()
{
    std::cout << Fibonachi_v<6>;
}
