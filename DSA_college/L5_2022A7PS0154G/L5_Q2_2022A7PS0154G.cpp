#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i,int k) {
    int largest = i;
    for(int j=1;j<=k;j++){
    int l = k*i + j;
    if(l < n && arr[l] > arr[largest]) {
        largest = l;
    }}
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest,k);
    }
}


void solve(vector<int>& A, int k)
{
    int n = A.size();
    for(int i=n/k;i>=0;i--){
        heapify(A,n,i,k);
    }
}
