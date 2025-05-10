#include <iostream>
#include <string>
#include <algorithm>

std::string double_number(const std::string &num)
{
        std::string result;
        int carry = 0;

        for (int i = num.size() - 1; i >= 0; --i)
        {
                int digit = (num[i] - '0') * 2 + carry;
                carry = digit / 10;
                digit %= 10;
                result.push_back(digit + '0');
        }

        if (carry > 0)
        {
                result.push_back(carry + '0');
        }

        std::reverse(result.begin(), result.end());
        return result;
}

int main()
{
        std::string number = "1";

        for (int i = 0; i < 1000; ++i)
        {
                number = double_number(number);
        }

        int sum = 0;
        for (char digit : number)
        {
                sum += digit - '0';
        }

        std::cout << "The sum of the digits in the number 2^1000 is: " << sum << std::endl;
        return 0;
}
