#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// brute force version
// int majorityElement(vector<int> &nums)
// {
//     int len = nums.size();
//     for (int val : nums)
//     {
//         int freq = 0;
//         for (int el : nums)
//         {
//             if (el == val)
//                 freq++;
//             if (freq > len / 2)
//                 return val;
//         }
//     }
//     return -1;
// }

// optimised version
int majorityElement(vector<int> &nums)
{
    int len = nums.size();

    sort(nums.begin(), nums.end());
    int freq = 1;
    int ans = nums[0];

    for (int i = 1; i < len; i++)
    {
        if (nums[i] == nums[i - 1])
            freq++;
        else
            freq = 1;
        ans = nums[i];

        if (freq > len / 2)
            return ans;
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 1, 3};

    int major = majorityElement(nums);
    cout << "majority element is:" << major << endl;

    return 0;
}