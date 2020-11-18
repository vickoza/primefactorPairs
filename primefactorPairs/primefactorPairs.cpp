// primefactorPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <vector>
int main()
{
    std::vector<long long> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    std::vector<std::pair<long long, long long>> prs;
    for( auto n = (long long)3; n < 10'000; ++n)
    {
        bool addPair = true;
        bool addPrime = true;
        for (const auto& pn : primes)
        {
            if (pn > n)
                break;
            if (addPair &&  n % pn != 0 && (n - 1) % pn != 0)
            {
                    addPair = false;
            }
            if (n % pn == 0)
                addPrime = false;
        }
        if(addPair)
            prs.emplace_back(n - 1, n);
        if (addPrime)
            primes.emplace_back(n);
    }
    for (const auto& prn : prs)
    {
        std::cout << prn.first << " -- " << prn.second << '\n';
    }
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
