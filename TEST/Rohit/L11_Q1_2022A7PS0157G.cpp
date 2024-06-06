#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solve(int n, int e, vector< pair<int,int> > edges) {
	vector< vector<int> > adj(n);

	vector<int> topo_sort;
	for(int i =0; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;
		adj[u].push_back(v);
	}
	vector<int>indeg(n,0);
	for(int i =0; i<n; i++){
		for(int v: adj[i]){
			indeg[v]++;
		}
	}
	priority_queue<int, vector<int>, greater<int>>pq;
	for(int i =0; i<n; i++){
		if(indeg[i]==0){
			pq.push(i);
		}
	}
	while(!pq.empty()){
		int u = pq.top();
		topo_sort.push_back(u);
		pq.pop();
		for(int v: adj[u]){
			indeg[v]--;
			if(indeg[v]==0){
				pq.push(v);
			}
		}
	}

	return topo_sort;
}
