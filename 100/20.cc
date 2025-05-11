#include <iostream>
#include <vector>

int main()
{
        std::vector<int> digits = {1}; // use vector to represent  our large number and each element stores a single digit starting with least sig

        for (int i = 2; i <= 100; i++)
        {
                int carry = 0;

                for (size_t j = 0; j < digits.size(); j++)
                {
                        int product = digits[j] * i + carry;
                        digits[j] = product % 10; // store the last digit
                        carry = product / 10;     // carry the rest
                }

                while (carry > 0)
                {
                        digits.push_back(carry % 10); // store the last digit
                        carry /= 10;                  // carry the rest
                }

                int sum = 0;
                for (int digit : digits)
                {
                        sum += digit;
                }

                std::cout << "Sum of digits in " << i << "! is: " << sum << std::endl;
        }
}