#include <bits/stdc++.h>
using namespace std;

    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=s.size();
        int left=0;
        int right=0;
        unordered_map<char,int> m;
        int len=0;
        while(right<n){
            if(m.count(s[right])) left = max(m[s[right]]+1,left);
            m[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }

    long long maximumSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        long long maxSum = 0, sum = 0;
        unordered_map<int, int> mp;
        for (int i=0; i<k; i++) {
            sum+=nums[i];
            mp[nums[i]]++;
        }
        
        if (mp.size()==k) {
            maxSum = max(sum, maxSum);
        }
        
        for (int i=k; i<n; i++) {
            sum+=nums[i];
            sum-=nums[i-k];
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if (mp[nums[i-k]]==0) {
                mp.erase(nums[i-k]);
            }
            if (mp.size()==k) {
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }

    int longestSubstring(string s,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=s.size();
        int left=0;
        int right=0;
        unordered_map<char,int> m;
        int len=0;
        while(right<n){
            m[s[right]]++;
            while(m.size()>k){
                m[s[left]]--;
                if(m[s[left]]==0) m.erase(s[left]);
                left++;
            }
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }

    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=s1.size();
        int m=s2.size();
        if(n>m) return false;
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(int i=0;i<n;i++){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if(m1==m2) return true;
        for(int i=n;i<m;i++){
            m2[s2[i-n]]--;
            if(m2[s2[i-n]]==0) m2.erase(s2[i-n]);
            m2[s2[i]]++;
            if(m1==m2) return true;
        }
        return false;
    }






int main(){


    return 0;
}