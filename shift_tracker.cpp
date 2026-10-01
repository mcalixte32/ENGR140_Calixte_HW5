/*
HW5 - Weekly Shift Tracker
Name: Mikeson Calixte
Date: September 30, 2026

1. A while loop checks its condition before running, so it may run zero
   times; a do-while loop checks afterward, so it runs at least once.
   A do-while loop fits the pay rate prompt because we must ask once and
   repeat the question if the rate is zero or negative.
   Source: LearnCpp, "8.9 - Do while statements"
   https://www.learncpp.com/cpp-tutorial/do-while-statements/

2. A sentinel is a special value that tells an algorithm to take a special
   action; here it ends input instead of being processed as a shift.
   The value -1 is safe because a valid shift cannot have negative hours.
   The value 8 would not be safe because an eight-hour shift is valid.
   Source: LearnCpp, "9.4 - Detecting and handling errors"
   https://www.learncpp.com/cpp-tutorial/detecting-and-handling-errors/
*/

#include <iostream>
#include <iomanip>

int main()
{
    double rate = 0.0;
    double hours = 0.0;
    int count = 0;
    double total = 0.0;
    double longest = 0.0;

    do
    {
        std::cout << "Enter your hourly pay rate ($): ";
        std::cin >> rate;

        if (rate <= 0)
        {
            std::cout << "Pay rate must be greater than 0. Try again.\n";
        }
    } while (rate <= 0);

    // Priming read: get the first value before checking the sentinel.
    std::cout << "Enter hours for shift " << count + 1
              << " (-1 to finish): ";
    std::cin >> hours;

    while (hours >= 0)
    {
        if (hours == 0 || hours > 16)
        {
            std::cout << "Invalid shift length, skipped.\n";
        }
        else
        {
            count++;
            total += hours;

            if (hours > longest)
            {
                longest = hours;
            }
        }

        // Bottom read: skipped entries keep the same shift number.
        std::cout << "Enter hours for shift " << count + 1
                  << " (-1 to finish): ";
        std::cin >> hours;
    }

    if (count == 0)
    {
        std::cout << "No shifts entered.\n";
        return 0;
    }

    double average = total / count;
    double pay = total * rate;

    std::cout << "\n====================================\n"
              << "Weekly Shift Summary\n"
              << "====================================\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(24) << "Shifts worked:"
              << std::right << std::setw(8) << count << '\n';
    std::cout << std::left << std::setw(24) << "Total hours:"
              << std::right << std::setw(8) << total << '\n';
    std::cout << std::left << std::setw(24) << "Average shift (hrs):"
              << std::right << std::setw(8) << average << '\n';
    std::cout << std::left << std::setw(24) << "Longest shift (hrs):"
              << std::right << std::setw(8) << longest << '\n';
    std::cout << std::left << std::setw(24) << "Estimated pay ($):"
              << std::right << std::setw(8) << pay << '\n';

    return 0;
}
