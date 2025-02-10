#include <iostream>
#include <vector>
using namespace std;

// binary search iterative
// time complexity O(logn)
// space complexity O(1)
int binarySearch(vector<int> arr, int target)
{
    // binary search works on sorted array
    int start = 0, end = arr.size() - 1; //  start of the array

    while (start <= end) // start is less than end, base case for two pointer approach
    {
        // int mid = start + end / 2; unoptimised , can thorw error in worst case when start and end both are INT_MAX addition operation is not possible
        int mid = start + (end - start) / 2; // mid of the array optimised calculation

        if (target < arr[mid]) // target is less than mid value
        {
            end = mid - 1; // reduce search space to 1st half of array
        }
        else if (target > arr[mid]) // greateer than the mid value
        {
            start = mid + 1; // reduce search space to 2nd half of array
        }
        else
        {
            return mid; // return the index of the target value
        }
    }
    return -1; // return -1 if  value not exist in the array
}

// Binary seach recursive
// time complexity O(logn)
// space complexity O(logn)
int binarySearchRecursive(vector<int> arr, int target, int start, int end)
{

    int mid = start + (end - start) / 2;

    if (start <= end)
    {
        if (target > arr[mid])
        {
            return binarySearchRecursive(arr, target, mid + 1, end);
        }
        else if (target < arr[mid])
        {
            return binarySearchRecursive(arr, target, start, mid - 1);
        }
        else
        {
            return mid; // base case if search found
        }

        return -1; // base case if value not found
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // sorted arrray

    cout << binarySearchRecursive(arr, 4, 0, arr.size()) << endl;
}