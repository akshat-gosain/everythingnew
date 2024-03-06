#include <bits/stdc++.h>
using namespace std;

void printVector(const std::vector<int>& vec) {
    for (int num : vec)
        cout << num << " ";
        cout << std::endl;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;

    
    vector<int> hash(n+1,0);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        hash[a] -= c;
        hash[b] += c;
    }

    int debt = 0;
    for(int i=1;i<=n;i++){
        if(hash[i] < 0){
            debt += hash[i];
        }
    }

    cout << abs(debt) << endl;
    // printVector(hash);

    
}