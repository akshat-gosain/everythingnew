#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int d;
    cin >> d;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>()); // Sort in descending order

    int count = 0;
    int k = 0;
    int j = 0;
    for(int i = 1; i <= n; i++){
        if((i-k)*a[j] > d){
            count++;
            j++;
            k=i;
        }
    }
    cout << count << endl;
    return 0;
}