#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int n) {
    string s = to_string(n);
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

int main() {
    int largestPalindrome = 0;
    for (int i = 999; i >= 100; --i) {
        for (int j = i; j >= 100; --j) {
            int product = i * j;
            if (isPalindrome(product)) {
                if (product > largestPalindrome) {
                    largestPalindrome = product;
                }
            }
        }
    }

    cout << "The largest palindrome made from the product of two 3-digit numbers is: " << largestPalindrome << endl;

    return 0;
}