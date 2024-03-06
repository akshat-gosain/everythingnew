#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums)
{
    int n = nums.size();
    if(n<3) return 0;

    sort(nums.begin(),nums.end());
    int count = 0;
    set<vector<int>> s;


    for(int i = 0; i<n ; i++){
        if(nums[i]>=0) break;

        int j = i+1, k = n-1;

        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum == 0) {
                s.insert({nums[i],nums[j],nums[k]});
                j++; k--;
            }
            else if(sum>0) {
                k--;
            }
            else j++;
        }
    }

    for(auto i : s){
        count++;
    }
    return count;
}
