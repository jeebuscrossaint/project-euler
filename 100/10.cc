#include <iostream>

using namespace std;

bool is_prime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  long long sum_of_primes = 0;
  int limit = 2000000;
  for (int i = 2; i < limit; ++i) {
    if (is_prime(i)) {
      sum_of_primes += i;
    }
  }
  cout << "The sum of all the primes below two million is: " << sum_of_primes
       << endl;
  return 0;
}
