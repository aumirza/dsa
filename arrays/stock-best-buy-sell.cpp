#include <iostream>
#include <vector>
#include <chrono>
#include "../benchmark.h"

using namespace std;

int maxProfit1(vector<int> prices)
{
    int maxProfit = 0;
    int bestBuy = prices[0];
    for (int i = 0, n = prices.size(); i < n; i++)
    {
        maxProfit = max(maxProfit, prices[i] - bestBuy);
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int maxProfit2(vector<int> prices)
{
    int maxProfit = 0;
    int bestBuy = prices[0];
    for (int i = 0, n = prices.size(); i < n; i++)
    {
        if (prices[i] < bestBuy)
        {
            bestBuy = prices[i];
        }
        else
        {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
    }
    return maxProfit;
}

// genrate vector of random numbers of size
vector<int> generateRandomVector(int size)
{
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        v.push_back(rand() % 100);
    }
    return v;
}

int main()
{

    vector<int> prices = generateRandomVector(10000);

    int max = benchmark(maxProfit1, prices);
    cout << "Maximum profit is using unoptimised:" << max << endl;

    max = benchmark(maxProfit2, prices);
    cout << "Maximum profit with optimised:" << max << endl;

    return 0;
}