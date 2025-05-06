#include <iostream>
#include <numeric>
#include <vector>

long long gcd(long long a, long long b)
{
  while(b) {
    a %= b;
    std::swap(a, b);
  }

  return a;
}

long long lcm(long long a, long long b)
{
  return (a * b) / gcd(a, b);
}

int main()
{
  long long result = 1;
  for (long long i = 2; i <= 20; ++i)
  {
    result = lcm(result, i);
  }

  std::cout << "the smallest positive number evenly divisible by all numbers from 1 to 20 is: " << result << std::endl;
  return 0;
}
