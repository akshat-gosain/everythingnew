#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int i,vector<int>& A,int k){
    int largest = i;
    int maxi=A[i];
    for(int j =k*i+k;j>=k*i+1; j--){
        if(j<A.size()){
            maxi=max(maxi,A[j]);
            if(maxi==A[j]){
                largest=j;
            }
        }
    }
    if(largest!=i){
        swap(A[largest],A[i]);
        maxHeapify(largest,A,k);
    }
}

void solve(vector<int>& A, int k)
{
    for(int i = (A.size()-2)/k; i>=0; i--){
        maxHeapify(i,A,k);
    }
}

