#include <iostream>

// Function to calculate the number of divisors of a number
int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            count += (i * i == n) ? 1 : 2;
        }
    }
    return count;
}

int main() {
    long long triangleNumber = 0;
    int naturalNumber = 1;
    int divisorCount = 0;
    int targetDivisors = 500;

    while (divisorCount <= targetDivisors) {
        triangleNumber += naturalNumber;
        divisorCount = countDivisors(triangleNumber);
        naturalNumber++;
    }

    std::cout << "The first triangle number to have over " << targetDivisors << " divisors is: " << triangleNumber << std::endl;

    return 0;
}
