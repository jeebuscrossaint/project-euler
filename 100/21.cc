#include <iostream>
#include <vector>

int sumOfProperDivisors(int n)
{
        int sum = 1;

        for (int i = 2; i * i <= n; i++)
        {
                if (n % i == 0)
                {
                        sum += i;
                        if (i != n / i)
                        {
                                sum += n / i;
                        }
                }
        }

        return sum;
}

int main()
{
        const int LIMIT = 10000;
        int totalSum = 0;

        for (int a = 2; a < LIMIT; a++)
        {
                int b = sumOfProperDivisors(a);

                if (b != a && b < LIMIT && sumOfProperDivisors(b) == a)
                {
                        totalSum += a;
                }
        }

        std::cout << "The sum of all amicable numbers under " << LIMIT << " is: " << totalSum << std::endl;
        return 0;
}