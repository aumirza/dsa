#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int len = nums.size();
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        num ^= nums[i];
    }
    return num;
}

int main()
{
    vector<int> a = {2, 2, 1, 4, 6, 6, 1};

    int num = singleNumber(a);

    cout << "Single number is:" << num << endl;

    /* code */
    return 0;
}
