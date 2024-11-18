#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int arrLen = 5;
    int maxSum = INT_MIN;
    int arr[arrLen] = {1, 2, 3, 4, 5};

    for (int st = 0; st < arrLen; st++)
    {
        int sum = 0;
        for (int end = st; end < arrLen; end++)
        {
            sum += arr[end];
            maxSum = max(maxSum, sum);
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;

    return 0;
}