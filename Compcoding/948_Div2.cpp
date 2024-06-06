// #include <bits/stdc++.h>
// using namespace std;

// int main(){

//     int t;
//     cin >> t;

//     while(t--){
//         int n, m;
//         cin >> n >> m;

//         if(n>=m){
//             if((n%2==0 && m%2==0) || (n%2==1 && m%2==1)){
//                 cout << "YES" << endl;
//             }else{
//                 cout << "NO" << endl;
//             }
//         }
//         else{
//             cout << "NO" << endl;
//         }
//     }


//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        if(n>=m){
            if((n%2==0 && m%2==0) || (n%2==1 && m%2==1)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }


    return 0;
}