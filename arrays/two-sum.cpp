#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    // nums must be sorted in ascending order to work
    vector<int> ans;
    int st_p = 0;
    int end_p = nums.size() - 1;

    while (st_p < end_p)
    {
        int sum = nums[st_p] + nums[end_p];
        cout << sum << endl;
        if (sum > target)
        {
            end_p--;
        }
        else if (sum < target)
        {
            st_p++;
        }
        else
            break;
    }

    ans.push_back(st_p);
    ans.push_back(end_p);

    return ans;
}

int main()
{

    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> ans = twoSum(nums, target);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
};
