// Problem 1.
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
// The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.
#include <iostream>

size_t CalculateSumOfMultiplesOfThreeOrFive(const size_t& target)
{
    size_t sum = 0;
    for (size_t i = 1; i < target; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            sum += i;
        }
    }
    return sum;
}

size_t SumDivisibleBy(const size_t& target, const size_t& n)
{
    size_t p = (target - 1) / n;
    return n * p * (p + 1) / 2;
}

size_t CalculateSumOfMultiplesOfThreeOrFive2(const size_t& target)
{
    return SumDivisibleBy(target, 3) + SumDivisibleBy(target, 5) - SumDivisibleBy(target, 15);
}

int main(void)
{
    std::cout << "Enter the num: " << std::endl;
    int num;
    std::cin >> num;

    std::cout << "Sum of multiples of 3 or 5 below " << num << " : " << CalculateSumOfMultiplesOfThreeOrFive(num) << std::endl;
    std::cout << "Sum of multiples of 3 or 5 below " << num << " : " << CalculateSumOfMultiplesOfThreeOrFive2(num) << std::endl;
    return 0;
}