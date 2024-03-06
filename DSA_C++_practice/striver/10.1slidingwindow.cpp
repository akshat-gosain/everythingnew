#include <bits/stdc++.h>
using namespace std;

//longest substring without repeating characters
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

    int totalFruits(vector<int>& tree) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=tree.size();
        int left=0;
        int right=0;
        unordered_map<int,int> m;
        int len=0;
        while(right<n){
            m[tree[right]]++;
            while(m.size()>2){
                m[tree[left]]--;
                if(m[tree[left]]==0) m.erase(tree[left]);
                left++;
            }
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
//minimum window substring t from a larger string s
  std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
        
        for (char c : t) {
            map[c]++;
        }

        while (end < s.length()) {
            if (map[s[end++]]-- > 0) {
                count--;
            }

            while (count == 0) {
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start++]]++ == 0) {
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }

//maximum consecutive ones with k flips
    int longestOnes(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=nums.size();
        int left=0;
        int right=0;
        int len=0;
        while(right<n){
            if(nums[right]==0) k--;
            while(k<0){
                if(nums[left]==0) k++;
                left++;
            }
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }

//longest substring with at most k distinct characters
    int lengthOfLongestSubstringKDistinct(string s, int k) {
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

//longest substring with at most k distinct characters

    int atMostK(vector<int>& A, int K) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int i = 0, res = 0;
        unordered_map<int, int> m;
        for (int j = 0; j < A.size(); j++) {
            if (m[A[j]] == 0) K--;
            m[A[j]]++;
            while (K < 0) {
                m[A[i]]--;
                if (m[A[i]] == 0) K++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        return atMostK(A, K) - atMostK(A, K - 1);
    }

//count number of nice subarrays. A continuous subarray is nice if there are k odd numbers on it

    int AtMostK(vector<int>& A, int K) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int i = 0, res = 0;
        for (int j = 0; j < A.size(); j++) {
            K -= A[j] % 2;
            while (K < 0) {
                K += A[i] % 2;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }

    int numberOfniceSubarraysKodd(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        return AtMostK(nums, k) - atMostK(nums, k - 1);
    }



int main(){


    return 0;
}