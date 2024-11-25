#include <iostream>
#include "../benchmark.h"

using namespace std;

double myPow(double x, int n)
{
    // edge cases
    if (n == 0)
        return 1.00;
    if (x == 0)
        return 0.00;
    if (x == 1)
        return 1.00;
    if (x == -1)
        return (n % 2 == 0) ? 1.00 : -1.00;

    long binForm = n;

    if (n < 0)
    {
        x = 1 / x;
        binForm = -binForm;
    }

    double ans = 1;

    while (binForm > 0)
    {
        if (binForm % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        binForm /= 2;
    }

    return ans;
}

int main()
{
    double ans = benchmark(myPow, 45, 4);
    cout << "Ans:" << ans << endl;

    return 0;
}