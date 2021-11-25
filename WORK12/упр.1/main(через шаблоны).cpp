#include <iostream>

template <std::size_t n>
struct Factorial
{
    static constexpr long value = Factorial<n - 1>::value * n;
};

template <>
struct Factorial<0>
{
    static constexpr long value = 1;
};

template <std::size_t n>
inline const long Factorial_v = Factorial<n>::value;

template <std::size_t n, std::size_t k >
struct Partial_factorial
{
    static constexpr long value = Partial_factorial<n - 1, k>::value * n;
};

template <std::size_t k>
struct Partial_factorial<k, k>
{
    static constexpr long value = 1;
};

template <std::size_t n, std::size_t k>
const long Partial_factorial_v = Partial_factorial<n, k>::value;

template <std::size_t n, std::size_t k>
struct Cnk
{
    static constexpr long value = Cnk<n-1, k>::value + Cnk<n-1, k-1>::value;
};

template <std::size_t k>
struct Cnk<k, k>
{
    static constexpr long value = 1;
};

template <std::size_t n>
struct Cnk<n, 0>
{
    static constexpr long value = 1;
};


template <std::size_t n, std::size_t k>
static constexpr long Cnk_v = Cnk<n, k>::value;

int main()
{
    std::cout << Cnk_v<10, 4>;
}
