#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, int> collatz_cache;

int collatz_length(long long n) {
    if (n == 1) return 1;
    if (collatz_cache.count(n)) return collatz_cache[n];

    int length = 1 + (n % 2 == 0 ? collatz_length(n / 2) : collatz_length(3 * n + 1));
    collatz_cache[n] = length;
    return length;
}

int main() {
    int max_start = 1;
    int max_length = 1;

    for (int i = 2; i < 1000000; ++i) {
        int length = collatz_length(i);
        if (length > max_length) {
            max_length = length;
            max_start = i;
        }
    }

    cout << "Starting number under 1,000,000 with the longest chain: " << max_start << endl;
    return 0;
}
