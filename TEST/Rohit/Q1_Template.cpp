// #include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <ios>
#include <iostream>
#include "__STUDENTPROGRAM__"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, e;
    cin>>t;

    while(t--)
    {
        cin >> n >> e;
        vector< pair<int,int> > edges (e);
        for (int i=0; i<e; i++)
        {
            cin >> edges[i].first >> edges[i].second;
        }

        vector<int> ans = solve(n, e, edges);

        if(ans.size()>0)
            for (int i=0; i < n; i++)
                cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
