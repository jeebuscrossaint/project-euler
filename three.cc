#include <iostream>
#include <cmath>

long long largest_prime_factor(long long n)
{
  long long largest = 1;
  long long d = 2;
  while (d * d <= n)
  {
    if (n % d == 0)
    {
      largest = d;
      n /= d;
      while (n % d == 0)
      {
        n /= d;
      }
    }
    d++;
    
  }

  if (n > largest) {
    largest = n;
  }

  return largest;
}

int main()
{
  long long magic = 600851475143;
  long long result = largest_prime_factor(magic);
  std::cout << " largest prime factor of " << magic << " is: " << result << std::endl;
  return 0;
}
