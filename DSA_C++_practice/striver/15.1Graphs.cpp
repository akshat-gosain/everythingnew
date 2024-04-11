#include <bits/stdc++.h>
using namespace std;

void printVector(const std::vector<int>& vec) {
    for (int num : vec)
        cout << num << " ";
        cout << std::endl;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> bfsOfGraph(int V, vector<int> adj[]){
    vector<int> vis(V+1,0);
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it); 
                vis[it]=1;
            }
        }
    }
    return bfs; // Added return statement
}

vector<int> dfsOfGraph(int V,vector<int> adj[]){
    vector<int> dfs;
    vector<int> vis(V+1,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs.push_back(i);
            stack<int> st;
            st.push(i);
            vis[i]=1;
            while(!st.empty()){
                int node = st.top();
                st.pop();
                for(auto it: adj[node]){
                    if(!vis[it]){
                        st.push(it);
                        vis[it]=1;
                        dfs.push_back(it);
                    }
                }
            }
        }
    }
    return dfs;
}

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls){
    ls.push_back(node);
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}


vector<int> dfsOfGraphRecursive(int V, vector<int> adj[]){
    vector<int> ls;
    vector<int> vis(V+1,0);
    dfs(0,adj,vis,ls);
    return ls;
}

vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges){
    vector<vector<int>> adjedges(V);
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjedges[u].push_back(v);
        adjedges[v].push_back(u);
    }
    return adjedges;
}

class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis){
        vis[node]=1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it,adjLs,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjLs(V);
        for(int i = 0;i<V;i++){
            for(int j = 0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(V, 0);
        int count = 0;
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i,adjLs,vis);
            }
        }
        return count;
    }
};




int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;

    
}