#include <iostream>

unsigned long long binomial_coefficient(int n, int k)
{
        unsigned long long result = 1;

        // symmetry: C(n, k) = C(n, n-k)
        if (k > n - k)
        {
                k = n - k;
        }

        // calculate C(n, k) = n! / (k! * (n-k)!)
        for (int i = 0; i < k; ++i)
        {
                result *= (n - i);
                result /= (i + 1);
        }

        return result;
}

int main()
{
        int grid_size = 20;

        // To reach bottom-right from top-left in a grid_size × grid_size grid:
        // - We need exactly grid_size moves to the right
        // - We need exactly grid_size moves down
        // - Total moves = 2 * grid_size
        // - The number of possible paths is C(2*grid_size, grid_size)

        unsigned long long routes = binomial_coefficient(2 * grid_size, grid_size);

        std::cout << "Number of routes through a " << grid_size << "x" << grid_size
                  << " grid: " << routes << std::endl;

        return 0;
}