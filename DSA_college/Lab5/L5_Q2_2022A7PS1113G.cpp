#include<bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &v,int i, int k){

    int n = v.size();

    vector<int> children(k);
    for(int j=0; j<k; j++){
        children[j] = (k*i) + (j+1);
    }

    int largest = i;

    for(int j=0 ; j<k; j++){
        if(children[j]<n && v[children[j]]>v[largest]) largest = children[j];
    }

    if(largest != i){
        int temp = v[i];
        v[i] = v[largest];
        v[largest] = temp;
        maxHeapify(v,largest,k);
    }

}

void buildMaxHeap(vector<int> &v, int k){
    int n = v.size();
    for(int i = (n/k)+1; i>=0; i--){
        maxHeapify(v,i,k);
    }
}

void solve(vector<int>& A, int k)
{
    buildMaxHeap(A,k);
}
