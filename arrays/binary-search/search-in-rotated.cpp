#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> arr, int target)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (target == arr[mid])
        {
            cout << "target matched" << endl;
            return mid;
        }

        if (arr[start] <= arr[mid])
        { // left side sorted
            cout << "left is sorted" << endl;
            if (arr[start] <= target && target <= arr[mid]) // if value lies in sorted
            {
                cout << "Value lies in left" << endl;
                end = mid - 1;
            }
            else
            {
                cout << "Value lies in right" << endl;
                start = mid + 1;
            }
        }
        else
        { // right side sorted
            cout << "right is sorted" << endl;
            if (arr[start] <= target && target <= arr[mid]) // if value lies in sorted
            {
                cout << "Value lies in right" << endl;
                start = mid + 1;
            }
            else
            {
                cout << "Value lies in left" << endl;
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << search(nums, target) << endl;
    return 0;
}