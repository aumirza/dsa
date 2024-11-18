#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// using moores voting algo
int majorityElement(vector<int> &nums)
{
    int freq = 0;
    int ans = 0;

    for (int val : nums)
    {
        if (freq == 0)
            ans = val;
        if (val == ans)
            freq++;
        else
            freq--;
    }
    return ans;
}

int main()
{
    vector<int> nums = {6, 5, 5};

    int major = majorityElement(nums);
    cout << "majority element is:" << major << endl;

    return 0;
}