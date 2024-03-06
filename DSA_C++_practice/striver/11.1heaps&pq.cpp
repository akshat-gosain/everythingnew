#include <bits/stdc++.h>
using namespace std;

void printVector(const std::vector<int>& vec) {
    for (int num : vec)
        cout << num << " ";
        cout << std::endl;
}

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapifymin(vector<int> &arr, int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && arr[l] < arr[smallest]) {
        smallest = l;
    }
    if(r < n && arr[r] < arr[smallest]) {
        smallest = r;
    }
    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifymin(arr, n, smallest);
    }
}



vector<int> buildHeap(vector<int> &arr,int n){
    for(int i = n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    return arr;
}

void buildMinHeap(vector<int> &arr, int n) {
    // Start from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifymin(arr, n, i);
    }
}

void heapsort(vector<int> &arr, int n){
    arr = buildHeap(arr, n);
    for(int i = n-1; i>0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapsortmin(vector<int> &arr, int n){
    buildMinHeap(arr, n);
    for(int i = n-1; i>0; i--){
        swap(arr[0], arr[i]);
        heapifymin(arr, i, 0);
    }
}

vector<int> MintoMaxHeap(vector<int> &arr, int n){
    buildMinHeap(arr, n);
    for(int i = n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    return arr;
}

void deleteRoot(vector<int> &arr, int n){
    swap(arr[0], arr[n-1]);
    heapify(arr, n-1, 0);
}

void insert(vector<int> &arr, int n, int key){
    arr.push_back(key);
    int i = n;
    n = n+1;
    while(i > 0 && arr[(i-1)/2] < arr[i]){
        swap(arr[i], arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int pop(vector<int> &heap)
{
    if(heap.size() == 0) return -1;
    int ans = heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    heapify(heap, heap.size(), 0);
    // Write you code here.
    return ans;
}

void push(vector<int> &heap, int x){
          heap.push_back(x);
           int pos=heap.size()-1;
           while(pos>0)
           {
               int parent = (pos-1)/2;
               if(heap[pos] > heap[parent])
               {
                   swap(heap[parent],heap[pos]);
                   pos=parent;
              }
             else
             {
                 break;
             }
         }
     }

int findKthLargest(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     nums = buildHeap(nums,n);
    //     for(int i = n-1, j=1; i>0; i--,j++){
    //     if(j==k) return nums[0];
    //     swap(nums[0], nums[i]);
    //     heapify(nums, i, 0);
    // }
    // return nums[0];
        priority_queue<int>pq ;
        int n = nums.size()  ;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i])  ;
        }
        int f = k - 1 ;
        while (f > 0) {
            pq.pop()  ;
            f-- ;
        }
    return pq.top();
    }

    int kth_Smallest_MinHeap(vector<int>&arr, int k) {
        priority_queue<int, vector<int>, greater<int>>pq ;
        int n = arr.size()  ;
        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i])  ;
        }
        int f = k - 1 ;
        while (f > 0) {
            pq.pop()  ;
            f-- ;
        }
        return pq.top();
    }

    vector<int> Karyheapify(vector<int> &arr, int n, int i, int k) {
        int largest = i;
        int child[k];
        for(int j = 0; j < k; j++){
            child[j] = k*i + j + 1;
        }
        for(int j = 0; j < k; j++){
            if(child[j] < n && arr[child[j]] > arr[largest]){
                largest = child[j];
            }
        }
        if(largest != i){
            swap(arr[i], arr[largest]);
            Karyheapify(arr, n, largest, k);
        }
        return arr;
    }

    vector<int> KarybuildHeap(vector<int> &arr, int n, int k){
        for(int i = n/k-1; i>=0; i--){
            Karyheapify(arr, n, i, k);
        }
        return arr;
    }

    vector<int> replacelementwithrank(vector<int> &arr, int n){
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for(int i = 0; i < n; i++){
            if(mp[temp[i]] == 0){
                mp[temp[i]] = rank;
                rank++;
            }
        }
        for(int i = 0; i < n; i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }

// //replaceelementsbyrank
//     int main()
// {
// 	int n = 6;
// 	int arr[n] = {20, 15, 26, 2, 98, 6};
// 	map<int, int>mp;
// 	int temp = 1;
// 	int brr[n];
// 	for (int i = 0; i < n; i++) {
// 		brr[i] = arr[i];
// 	}
// 	sort(brr, brr + n);
// 	for (int i = 0; i < n; i++) {
// 		//if element is previously not store in the map
// 		if (mp[brr[i]] == 0) {
// 			mp[brr[i]] = temp;
// 			temp++;
// 		}
// 	}
// 	for (int i = 0; i < n; i++) {
// 		cout << mp[arr[i]] << " ";
// 	}
// }

int minLaptops(int N, int start[], int end[]) {
        // Create a map to store the count of laptops needed at each time point
        map<int,int>mp;
        
        // Iterate through the start and end arrays
        for(int i=0; i<N; i++)
        {
            // Increment the count for start time and decrement the count for end time
            mp[start[i]] += 1;
            mp[end[i]] -= 1;
        }
        
        // Create a vector to store the time points and their corresponding counts
        vector<pair<int,int>> s;
        
        // Iterate through the map and store the pairs in the vector
        for(auto it: mp)
            s.push_back(it);
        
        // Sort the vector in ascending order based on time points
        sort(s.begin(), s.end());
        
        // Initialize variables for counting laptops and storing the maximum count
        int c=0,ans=0;
        
        // Iterate through the vector of time points and counts
        for(pair<int,int> i:s)
        {
            // Update the count of laptops
            c+=i.second;
            
            // Update the maximum count if necessary
            ans=max(ans,c);
        }
        
        // Return the maximum count of laptops required
        return ans;
    }

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }
        sort(count.begin(), count.end());
        int maxCount = count[25];
        int idleTime = (maxCount - 1) * n;
        for (int i = 24; i >= 0; i--) {
            idleTime -= min(count[i], maxCount - 1);
        }
        return idleTime > 0 ? idleTime + tasks.size() : tasks.size();
    }

    int leastInervalPriorityQueue(vector<char>& tasks, int n) {
    
        vector<int> count(26, 0);
    for (char task : tasks) {
        count[task - 'A']++;
    }
    
    priority_queue<int> pq;
    for (int c : count) {
        if (c > 0) {
            pq.push(c);
        }
    }
    
    int alltime = 0;
    while (!pq.empty()) {
        int time = 0;
        vector<int> tmp;
        for (int i = 0; i < n + 1; ++i) {
            if (!pq.empty()) {
                tmp.push_back(pq.top() - 1);
                pq.pop();
                time++;
            }
        }
        for (int cnt : tmp) {
            if (cnt > 0) {
                pq.push(cnt);
            }
        }
        alltime += pq.empty() ? time : n + 1;
    }
    return alltime;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto i : mp){
            pq.push({i.second, i.first});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    int findPlatforms(int arr[], int dep[], int n) {
        sort(arr, arr + n);
        sort(dep, dep + n);
        int i = 1, j = 0, res = 1, plat = 1;
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                plat++;
                i++;
            } else if (arr[i] > dep[j]) {
                plat--;
                j++;
            }
            res = max(res, plat);
        }
        return res;
    }

    int findPlatformspq(int arr[], int dep[], int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(arr, arr + n);
        sort(dep, dep + n);
        int i = 0, j = 0, res = 0;
        while (i < n) {
            if (arr[i] <= dep[j]) {
                pq.push(arr[i]);
                i++;
            } else {
                pq.pop();
                j++;
            }
            res = max(res, (int)pq.size());
        }
        return res;
    }

    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (long long i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        long long res = 0;
        while (pq.size() > 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            res += first + second;
            pq.push(first + second);
        }
        return res;
    }

    int minRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }

    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0, i = 0, n = events.size();
        for (int d = 1; d <= 100000; d++) {
            while (i < n && events[i][0] == d) {
                pq.push(events[i++][1]);
            }
            while (!pq.empty() && pq.top() < d) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                res++;
            }
        }
        return res;
    }

    vector<int> mergeKsortedArrays(vector<vector<int>> arr, int K) {
        vector<int> res;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < K; i++) {
            pq.push({arr[i][0], {i, 0}});
        }
        while (!pq.empty()) {
            pair<int, pair<int, int>> curr = pq.top();
            pq.pop();
            res.push_back(curr.first);
            int x = curr.second.first;
            int y = curr.second.second;
            if (y + 1 < K) {
                pq.push({arr[x][y + 1], {x, y + 1}});
            }
        }
        return res;
    }

    vector<int> roomUsage(vector<vector<int>>& intervals, int n) {
    sort(intervals.begin(), intervals.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> usage(n, 0);
    int room = 0;
    for (int i = 0; i < intervals.size(); i++) {
        if (!pq.empty() && intervals[i][0] >= pq.top().first) {
            room = pq.top().second;
            pq.pop();
        } else if (room < n) {
            usage[room]++;
        } else {
            continue;
        }
        pq.push({intervals[i][1], room});
        if (room < n - 1) {
            room++;
        }
    }
    return usage;
}











int main(){
    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i<n; i++){
        cin >> vec[i];
    }

    // int m;
    // cin >> m;
    // heapsort(vec, n);
    // insert(vec, n, m);
    buildHeap(vec, n);
    heapsort(vec, n);
    printVector(vec);


    



//replaceelementsbyrank

    // n = 6;
	// int arr[n] = {20, 15, 26, 2, 98, 6};
	// map<int, int>mp;
	// int temp = 1;
	// int brr[n];
	// for (int i = 0; i < n; i++) {
	// 	brr[i] = arr[i];
	// }
	// sort(brr, brr + n);
	// for (int i = 0; i < n; i++) {
	// 	//if element is previously not store in the map
	// 	if (mp[brr[i]] == 0) {
	// 		mp[brr[i]] = temp;
	// 		temp++;
	// 	}
	// }
	// for (int i = 0; i < n; i++) {
	// 	cout << mp[arr[i]] << " ";
	// }

    return 0;
}

// class minHeap {
// public:


//    int *heap;
//    int heapsize;
//     minHeap(int c) {
//        heapsize=0;
//        heap=new int[c];
//     }


//     int extractMinElement() {
//      if(heapsize<1)return -1;
//      if(heapsize==1)
//      {
//          heapsize--;
//          return heap[0];
//      }
//      int ans=heap[0];
//      heapsize--;
//      heap[0]=heap[heapsize];
//      heap[heapsize]=0;
//      heapify(0);
//      return ans;
//     }


//     void deleteElement(int ind) {
//         if(ind<heapsize)
//         {
//             decreaseKey(ind);
//             extractMinElement();
//         }
//     }


//     void insert(int val) {
//         int ind=heapsize;
//         heapsize++;
//         heap[ind]=val;
//         while(ind>0)
//         {
//             if(heap[ind]<heap[parent(ind)])
//             {
//                 swap(heap[ind],
//                     heap[parent(ind)]);
//                 ind=parent(ind);
//             }
//             else break;
//         }
//     }
    
//     //created sepearet fucn for just simplicity
//     void heapify(int ind)
//     {
//         int smallest=ind;
//         int l=lchild(ind);
//         int r=rchild(ind);
        
//         if(l<heapsize && 
//           heap[smallest]>heap[l])smallest=l;
//         if(r<heapsize &&
//           heap[smallest]>heap[r])smallest=r;
//         if(smallest!=ind)
//         {
//             swap(heap[ind],heap[smallest]);
//             heapify(smallest);
//         }
//     }


//     void decreaseKey(int ind)
//     {
//         heap[ind]=INT_MIN;
//         while(ind>0)
//         {
//             if(heap[ind]<heap[parent(ind)])
//             {
//                 swap(heap[ind],
//                      heap[parent(ind)]);
//                 ind=parent(ind);
//             }
//             else break;
//         }
//     }
    
//     int parent(int i)
//     {
//         return (i-1)/2;
//     }
//     int rchild(int i)
//     {
//         return 2*i+2;
//     }
//     int lchild(int i)
//     {
//         return 2*i+1;
//     }
// };


// class minHeap {
// public:
//     vector<int> heap;
//     int size, capacity;
//     // Constructor for the class.
//     minHeap(int cap) {
//         // Write your code here.
//         heap.resize(cap);
//         size = 0;
//         capacity = cap;
//     }

//     void heapify(int i) {
//         int smallest = i;
//         int li = 2*i + 1, ri = 2*i + 2;
//         if(li < size && heap[li] < heap[smallest]) {
//             smallest = li;
//         }

//         if(ri < size && heap[ri] < heap[smallest]) {
//             smallest = ri;
//         }

//         if(i != smallest) {
//             swap(heap[i],heap[smallest]);
//             heapify(smallest);
//         }
//     }

//     // Implement the function to remove minimum element.
//     int extractMinElement() {
//         // Write you code here.
//         if(size == 0) return -1;
//         int ans = heap[0];
//         swap(heap[0],heap[size-1]);
//         size--;
//         heapify(0);
//         return ans;
//     }

//     // Implement the function to delete an element.
//     void deleteElement(int ind) {
//         // Write you code here.
//         if(ind >= size) return ;
//         swap(heap[ind],heap[size-1]);
//         size--;
//         heapify(ind);
//     }

//     // Implement the function to insert 'val' in the heap.
//     void insert(int val) {
//         // Write you code here.
//         if(size == capacity) return ;
//         heap[size] = val;
//         size++;
//         int ind = size-1;
//         while(ind >= 0) {
//             int parent = (ind-1)/2;
//             if(heap[parent] > heap[ind]) {
//                 swap(heap[parent],heap[ind]);
//                 ind = parent;
//             }else break;
//         }
//     }
// };

class MedianFinder{
    public:
    //max heap
    priority_queue<int> maxHeap;
    //min heap
    priority_queue<int,vector<int>,greater<int>> minHeap;

    MedianFinder(){
        // Clear the heaps
        while(!maxHeap.empty()) maxHeap.pop();
        while(!minHeap.empty()) minHeap.pop();
    }
    void addNum(int num){
        if(maxHeap.empty() || maxHeap.top() > num){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian(){
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }else if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }else{
            return minHeap.top();
        }
    }
};

