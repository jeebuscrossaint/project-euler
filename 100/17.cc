#include <iostream>
#include <string>
#include <vector>

// Function to count letters in the word representation of a number
int numberToWordCount(int number)
{
        // Define word arrays for different number components
        std::vector<std::string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                                         "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                                         "sixteen", "seventeen", "eighteen", "nineteen"};
        std::vector<std::string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

        int count = 0;

        // Handle the special case for 1000
        if (number == 1000)
        {
                return ones[1].length() + std::string("thousand").length();
        }

        // Handle hundreds place
        if (number >= 100)
        {
                count += ones[number / 100].length() + std::string("hundred").length();
                if (number % 100 != 0)
                {
                        // Add "and" for British usage when there are remaining digits
                        count += std::string("and").length();
                }
        }

        // Handle tens and ones place
        int remainder = number % 100;
        if (remainder > 0)
        {
                if (remainder < 20)
                {
                        // Special handling for 1-19
                        count += ones[remainder].length();
                }
                else
                {
                        // For 20-99
                        count += tens[remainder / 10].length();
                        if (remainder % 10 != 0)
                        {
                                count += ones[remainder % 10].length();
                        }
                }
        }

        return count;
}

int main()
{
        int totalCount = 0;

        // Count letters for all numbers from 1 to 1000
        for (int i = 1; i <= 1000; i++)
        {
                totalCount += numberToWordCount(i);
        }

        std::cout << "Total letters: " << totalCount << std::endl;

        return 0;
}