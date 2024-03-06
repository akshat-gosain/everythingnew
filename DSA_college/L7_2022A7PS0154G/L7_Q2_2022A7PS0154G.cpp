#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a , long long k){

    int max_len = 0;
    int l=0;
    int n = a.size();
    int i = 0;
    int j = 0;
    long long sum = a[0];
    while(j<n){
        while(i<j && sum>k){
                sum-=a[i];
                i++;
            }
        if(sum==k){
            max_len = max(max_len, j-i+1);
        }
        j++;
        if(j<n) sum += a[j];
       
    }
    return max_len;
}
