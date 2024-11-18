#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int arrLen = 5;
    int maxSum = INT_MIN;
    int sum = 0;
    int arr[arrLen] = {1, 2, 3, 4, 5};

    for (int i = 0; i < arrLen; i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
            sum = 0; // reset the sum to remove sum of previous subarray
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;

    return 0;
}