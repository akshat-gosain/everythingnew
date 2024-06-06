#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    printVector(v);

    return 0;
}