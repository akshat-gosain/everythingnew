#include<bits/stdc++.h>
#include "./L5_Q2_2022A7PS0154G.cpp"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t>0)
    {
        t--;
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0; i<n; i++)
            cin>>v[i];
        solve(v, k);
        for(int i=0; i<n; i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
}
