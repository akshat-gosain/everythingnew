#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string a;
cin >> a;

int maxconsecutiveones = 0;
int currentconsecutiveones = 0;

// Concatenate the string to itself to handle the cyclic condition
a += a;

for(int i = 0; i < a.size(); i++){
    if(a[i] == '1'){
        currentconsecutiveones++;
        maxconsecutiveones = max(maxconsecutiveones, currentconsecutiveones);
    } else {
        currentconsecutiveones = 0;
    }
}

// Ensure we don't count cycles more than once
maxconsecutiveones = min(maxconsecutiveones, (int)a.size()/2);



        if(maxconsecutiveones == 0){
            cout << 0 << endl;
        } else if(maxconsecutiveones == 1){
            cout << 1 << endl;
        } else {
            cout << 2*(maxconsecutiveones-1) << endl;
        }
        
    }

    return 0;
}