#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int stInd = 0;
    int endInd = height.size() - 1;
    int maxW = 0;

    while (stInd < endInd)
    {
        int wt = endInd - stInd;
        int ht = min(height[stInd], height[endInd]);
        maxW = max(maxW, ht * wt);
        height[stInd] > height[endInd] ? endInd-- : stInd++;
    }

    return maxW;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int mxArea = maxArea(height); // 49
    cout << mxArea << endl;
}