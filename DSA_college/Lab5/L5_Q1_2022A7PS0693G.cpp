#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int a = 0;
    int b = n - 1;
    int c;
    int count = 0;
    bool flip = true;

    while (true) {
        for (c = a + 1; c < b; c++) {
            if (nums[a] + nums[b] + nums[c] == 0) {
                count++;
            }
        }
        if (nums[a] <= 0 && flip) {
            while (nums[a] == nums[a + 1]) {
                a++;
            }
            a++;
            if(nums[a] >= 0) a = 0; flip = false;
        }
        else {
            while (nums[b] == nums[b - 1]) {
                b--;
            }
            b--;
            if (nums[b] <= 0) break;
        }
        
    }
    return count;
}
