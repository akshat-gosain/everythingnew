#include <bits/stdc++.h>
using namespace std;

void printVector(const std::vector<long long>& vec) {
    for (long long num : vec)
        cout << num << " ";
        cout << std::endl;
}

int main() {
    long long m;
    cin >> m;

    while(m--) {
        long long n;
        cin >> n;
        vector<long long> a(n,0);
        for(long long i = 0; i < n; i++){
            cin >> a[i];
        }
        if(a[0]==1) a[0]=3;

        for(long long i = 0; i < n-1; i++){
            if(a[i+1]==1){ a[i+1]=2;}
            if(a[i+1]%a[i]==0){
                a[i+1]+=1;
            }
        }
        
        printVector(a);
    }
    return 0;
}