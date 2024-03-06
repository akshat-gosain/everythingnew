#include <bits/stdc++.h>
using namespace std;

void printVector(const std::vector<long long>& vec) {
    for (long long num : vec)
        cout << num << " ";
        cout << std::endl;
}

void printUnorderedMap(const std::unordered_map<long long, long long>& map) {
    for (auto it = map.begin(); it != map.end(); ++it)
        cout << it->first << " " << it->second << endl;
}

int find_index(std::vector<long long>& arr, long long target) {
    // Pair of (value, index), sorted by value
    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long,long long>>, std::greater<>> pq;
    for (long long i = 0; i < arr.size(); ++i) {
        pq.push({arr[i], i});
    }
    while (!pq.empty()) {
        auto [value, index] = pq.top();
        pq.pop();
        if (value > target) {
            return index;
        }
    }
    return -1;  // return -1 if no element is greater than target
}

long long find_index1(vector<long long> arr, long long target) {
    long long low = 0;
    long long high = arr.size() - 1;
    long long ans = -1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    
    long long n;
    cin >> n;

    while(n--){
        long long h;
        cin >> h;
        long long q;
        cin >> q;

        vector<long long> steps(h);
        for(long long i = 0; i < h; i++){
            cin >> steps[i];
        }

        
        vector<long long> qs(q,0);
        for(long long i = 0; i < q; i++){
        cin >> qs[i];
        }

        // map<long long, long long> sumtill;
        // sumtill[steps[0]] = 0;
        // for(long long i = 1; i < h; i++){
        //     sumtill[steps[i]] = sumtill[steps[i-1]] + steps[i];
        // }

        // unordered_map<long long, long long> sumtill;
        // long long sum = 0;
        // for(long long i = 0; i < h; i++){
        //     sum += steps[i];
        //     if(sumtill.count(steps[i]) == 0) { // Check if the key is not already present in the map
        //     sumtill[steps[i]] = sum;
        //     }
    
        // }

        // vector<long long> sumtill(h,0);
        // long long sum = 0;
        // for(long long i = 0; i < h; i++){
        //     sum += steps[i];
        //     sumtill[i] = sum;
        // }

    // printUnorderedMap(sumtill);

        vector<long long> maxheight(h,0);
        long long maxele = steps[0];
        for(int i = 0; i < h; i++){
            if(steps[i] > maxele){
                maxele = steps[i];
            }
            maxheight[i] = maxele;
        }
        

        vector<long long> sumtill(h,0);
        long long sum = 0;
        for(long long i = 0; i < h; i++){
            sum += steps[i];
            sumtill[i] = sum;
        }

        unordered_map<long long, long long> justgreaterindex;
        for(long long i = 0; i < h; i++){
            justgreaterindex[maxheight[i]] = i;       
        }
        printUnorderedMap(justgreaterindex);
        // printVector(maxheight);
        // printVector(sumtill);

        for(long long i = 0; i < q; i++){
            int index = find_index1(maxheight, qs[i]);
            if(index == -1){
                cout << sumtill[h-1] << " ";
            }
            else{
                cout << ((index == 0) ? 0 : sumtill[index-1]) << " ";
            }
        }
        cout << endl;

        // vector<long long> ans(q,0);
//         for(long long i = 0; i < q; i++){
//     for(long long j = 0; j < h; j++){
//         if(qs[i] < steps[j]){
//             ans[i] = (j == 0) ? 0 : sumtill[j-1];
//             break;
//         }
//         else if(j == h-1){
//             ans[i] = sumtill[h-1];
//         }
//     }
// }

//         for(long long i = 0; i < q; i++){
//             int index = find_index(steps, qs[i]);
//             if(index == -1){
//                 ans[i] = sumtill[h-1];
//             }
//             else{
//                 ans[i] = (index == 0) ? 0 : sumtill[index-1];
//             }
// }


        // printVector(ans);

        // printVector(ans);
    }
    return 0;
}