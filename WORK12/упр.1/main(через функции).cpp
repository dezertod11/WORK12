#include <iostream>

constexpr double bin(double n , double k) {
    if (n <= 0 || k < 0 || n < k) {
        std::cout << "Incorrect data" << std::endl;
        return false;
    }
    if ( k == 0   || ( n == 1) ) {
        return 1;
    }
    if (n > k) {
        return bin(n - 1, k - 1) + bin(n - 1, k);
    }
    else return bin(n - 1, k - 1);
}

int main() {
    std::cout << bin( 5, 1) << std::endl;
    return 0;
}
