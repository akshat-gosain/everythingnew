// #include <bits/stdc++.h>
// using namespace std;


// int main() {
//     int m;
//     cin >> m;

//     while(m--) {
//         int n;
//         cin >> n;

//         vector<int> a(n);
//         for(int i = 0; i < n; i++){
//             cin >> a[i];
//         }
//         int count =0;
//         for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                 if(a[j]- a[i]==j-i){
//                     count++;
//                 }
//             }
//         }
//         cout << count << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;

    while(m--) {
        int n;
        cin >> n;

        vector<int> a(n);
        unordered_map<int, int> diff;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            diff[a[i] - i]++;
        }

        int count = 0;
        for(auto &it : diff){
            int val = it.second;
            count += (val * (val - 1)) / 2; // Combination of nC2
        }
        cout << count << endl;
    }
    return 0;
}
