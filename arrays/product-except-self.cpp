#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 1; i < n; i++)
    {
        ans[i] = nums[i - 1] * ans[i - 1];
    }

    int suffix = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> products = productExceptSelf(nums);

    for (int i = 0; i < products.size(); i++)
    {
        cout << products[i] << endl;
    }

    return 0;
}