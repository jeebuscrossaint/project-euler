#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    int count = 0;
    int number = 2;
    while (count < 10001) {
        if (isPrime(number)) {
            count++;
        }
        if (count == 10001) {
            std::cout << "The 10001st prime number is: " << number << std::endl;
            break;
        }
        number++;
    }
    return 0;
}