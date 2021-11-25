#include <iostream>
#include <array>

template <std::size_t n>
constexpr int prime()
{
    std::array<int, n> arr;
    int num = 3;
    arr[0] = 2;
    for (auto cnt = 1; cnt < n; num += 2)
    {
        bool flag = true;
        for (auto i = 0; (i < cnt) && (arr[i] * arr[i]) <= num; ++i)
        {
            if (num % arr[i] == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {

            arr[cnt] = num;
            cnt++;
        }
    }
    return arr[n - 1];
}

int main()
{
    std::cout << prime<5>();
}
