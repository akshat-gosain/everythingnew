#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &a){
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int> maxelementinwindowsizekpq(vector<int> &a, int k){
    // check if the vector is empty or k is invalid
    if (a.empty() || k <= 0 || k > a.size()) {
        return {};
    }
    int n = a.size();
    vector<int> result;
    // use a pair to store the value and the index of each element
    priority_queue<pair<int, int>> pq;
    for(int i=0;i<k;i++){
        pq.push({a[i], i});
    }
    // get the maximum element of the first window
    result.push_back(pq.top().first);
    for(int i=k;i<n;i++){
        // push the new element into the priority queue
        pq.push({a[i], i});
        // remove the elements that are out of the window
        while (!pq.empty() && pq.top().second <= i-k) {
            pq.pop();
        }
        // get the maximum element of the current window
        result.push_back(pq.top().first);
    }
    return result;
}




int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> result = maxelementinwindowsizekpq(a,k);
    printVector(result);
    
}
