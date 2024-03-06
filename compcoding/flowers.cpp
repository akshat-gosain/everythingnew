// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     long long r,g,b;
//     cin >> r >> g >> b;
//     long long ans=0;
//     long long minimum = min(r,min(g,b));

//     ans = minimum;
    
//     ans+=(r-minimum)/3 + (g-minimum)/3 + (b-minimum)/3;

//     long long ans2=0;
//     ans2 = (r/3) + (g/3) + (b/3);
//     ans2 += min(r%3,min(g%3,b%3));

//     ans = max(ans,ans2);
    

//     cout << ans << endl;

// }

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long r,g,b;
    cin >> r >> g >> b;
    long long ans=0;
    for(int i=0; i<3; i++) {
        if(r>=i && g>=i && b>=i) {
            long long nr = r-i;
            long long ng = g-i;
            long long nb = b-i;
            long long total = nr/3 + ng/3 + nb/3 + i;
            ans = max(ans, total);
        }
    }
    cout << ans << endl;
}
