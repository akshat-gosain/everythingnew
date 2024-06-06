#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &a){
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
}



int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }

    
    // sort(a.begin(),a.end());
    printVector(a);
}