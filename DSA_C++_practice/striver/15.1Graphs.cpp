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

class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        // int dx[] = {-1,0,1,0};
        // int dy[] = {0,1,0,-1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // for(int i=0;i<4;i++){
            //     int r = x + dx[i];
            //     int c = y + dy[i];
            //     if(r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1' && !vis[r][c]){
            //         vis[r][c]=1;
            //         q.push({r,c});
            //     }
            // }
            for(int delrow = -1;delrow<=1;delrow++){
                for(int delcol = -1;delcol<=1;delcol++){
                    int r = x + delrow;
                    int c = y + delcol;
                    if(r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1' && !vis[r][c]){
                        vis[r][c]=1;
                        q.push({r,c});
                    }
                }
            }   
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,grid,vis);
                }
            }
        }
        return cnt;
    }
};

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>>&image,int newColor, int delRow[], int delCol[],int iniColor){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && image[nrow][ncol] == iniColor && ans[nrow][ncol]!=newColor){
                dfs(nrow,ncol,ans,image,newColor,delRow,delCol,iniColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        dfs(sr,sc,ans,image,color,delRow,delCol,iniColor);
        return ans;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // {{r,c},t} or {{row,col},time}
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
            
        }
        int tm = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
                int r = q.front().first.first;
                int c = q.front().first.second;
                int t = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr = r + drow[i];
                    int nc = c + dcol[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=2 && grid[nr][nc]==1 ){
                        vis[nr][nc]=2;
                        q.push({{nr,nc},t+1});
                        tm = max(tm,t+1);
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(vis[i][j]==1){
                        return -1;
                    }
                }
            }
        return tm;
    }
};


//Bridges in Graph - Using Tarjan's Algorithm of time in and low time: G-55
//Problem Statement: There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
//A critical connection is a connection that, if removed, will make some servers unable to reach some other servers.
//Return all critical connections in the network in any order.

class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                // node --- it
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n,
    vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};



//Articulation Point in Graph: G-56
//Problem Statement: Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnect the graph into 2 or more components.
//Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.
class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
             vector<int> &mark, vector<int>adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) return { -1};
        return ans;
    }
};


//Strongly Connected Components - Kosaraju's Algorithm: G-54
//Problem Statement: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
private:
    void dfs3(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }
public:
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};


//Cycle Detection in Undirected Graph: G-53
class Solution {
private:
    void DFS(int node, vector<int>& edges, vector<bool>& currVisited, vector<bool>& visited, vector<int>& dist)
    {
        if (currVisited[node])
        {
            maxCycle = max(maxCycle, dist[node]);
            return;
        }
        if (visited[node])
        {
            return;
        }
        visited[node] = true;
        currVisited[node] = true;
        DFS(edges[node], edges, currVisited, visited, dist);
        currVisited[node] = false;
        dist[node] = 1 + dist[edges[node]];
    }
    int maxCycle;
public:
    int longestCycle(int n,vector<int>& edges) {
        maxCycle = -1;
    vector<bool> visited(n), currVisited(n);
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dist[i] = 0;
            DFS(i, edges, currVisited, visited, dist);
        }
    }
    return maxCycle;
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