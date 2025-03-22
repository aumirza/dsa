#include <iostream>
#include <vector>
using namespace std;

// must be mountain array
// no duplicate peak
// min length 3
// peak is not first neihter last
int findPeakIndex(vector<int> arr)
{
    int st = 1;
    int end = arr.size() - 2;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) // peak condition
            return mid;

        if (arr[mid] > arr[mid - 1]) // still increasing, peak is on right
            st = mid + 1;
        else // decreasing, peak is on left
            end = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> mountain = {0, 1, 2, 3, 4, 5, 3, 2, 1};
    cout << findPeakIndex(mountain) << endl;
    return 0;
}