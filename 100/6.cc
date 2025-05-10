#include <iostream>

int main() {
    long long sumOfSquares = 0;
    long long sum = 0;

    for (int i = 1; i <= 100; ++i) {
        sumOfSquares += (long long)i * i;
        sum += i;
    }

    long long squareOfSum = sum * sum;
    long long difference = squareOfSum - sumOfSquares;

    std::cout << "The sum of the squares of the first one hundred natural numbers is: " << sumOfSquares << std::endl;
    std::cout << "The square of the sum of the first one hundred natural numbers is: " << squareOfSum << std::endl;
    std::cout << "The difference between the square of the sum and the sum of the squares is: " << difference << std::endl;

    return 0;
}