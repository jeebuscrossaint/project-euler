#include <iostream>

int main()
{
  long long a = 1;
  long long b = 2;
  long long sum = 0;

  while (b <= 4000000)
  {
    if (b % 2 == 0)
    {
      sum += b;
    }

    long long next = a + b;
    a = b;
    b = next;
  }

  std::cout << "sum of the fibs less than 4 million: " << sum << std::endl;

  return 0;
}
