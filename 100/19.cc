#include <iostream>
#include <vector>

// Function to check if a year is a leap year
bool isLeapYear(int year)
{
        if (year % 400 == 0)
                return true;
        if (year % 100 == 0)
                return false;
        return (year % 4 == 0);
}

int main()
{
        // Days in each month (index 0 = January, 1 = February, etc.)
        std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // January 1, 1900 was a Monday (day-of-week 1)
        int dayOfWeek = 1;
        int sundayCount = 0;

        // Iterate through years and months
        for (int year = 1900; year <= 2000; ++year)
        {
                for (int month = 0; month < 12; ++month)
                {
                        // Check if the first of the month is a Sunday (day-of-week 0)
                        if (dayOfWeek == 0 && year >= 1901)
                        {
                                sundayCount++;
                        }

                        // Calculate days in current month
                        int days = daysInMonth[month];
                        if (month == 1 && isLeapYear(year))
                        { // February in a leap year
                                days = 29;
                        }

                        // Calculate the day of the week for the first of the next month
                        dayOfWeek = (dayOfWeek + days) % 7;
                }
        }

        std::cout << "Number of Sundays that fell on the first of the month: " << sundayCount << std::endl;

        return 0;
}