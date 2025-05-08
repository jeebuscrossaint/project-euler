#include <iostream>

using namespace std;

int main() {
  for (int a = 1; a < 1000; ++a) {
    for (int b = a + 1; b < 1000; ++b) {
      int c = 1000 - a - b;
      if (b < c && a * a + b * b == c * c) {
        cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
        long long product = (long long)a * b * c;
        cout << "The product abc is: " << product << endl;
        return 0;
      }
    }
  }
  return 0;
}
