#include<bits/stdc++.h>
using namespace std;

void max_heapify (vector<int>& A, int n, int i, int k) {
    int largest = i;
    int left = k*i + 1;
    int right = k*i + k;
    int j = left;

    while (j <= right && j < n) {
        if (A[largest] < A[j]) {
            if (A[largest] < A[j]){
                largest = j;
            }
        }
        j++;
    }

    if (largest != i) {
        swap(A[largest], A[i]);
        max_heapify(A, n, largest, k);
    }

}

void solve(vector<int>& A, int k)
{   
    int n = A.size();
    for (int i = n/k; i>= 0; i--) {
        max_heapify(A, n, i, k);
    }
}
