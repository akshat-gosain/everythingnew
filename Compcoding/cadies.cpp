#include <vector>
#include <iostream>
using namespace std;

int count_elements(std::vector<int>& arr) {
    int sumL = 0, sumR = 0;
    int i = 0, j = arr.size() - 1;
    int maxCount = 0;
    while (i <= j) {
        if (sumL < sumR) {
            sumL += arr[i];
            i++;
        } else {
            sumR += arr[j];
            j--;
        }
        if (sumL == sumR) {
            maxCount = std::max(maxCount, i + static_cast<int>(arr.size()) - 1 - j);
        }
    }
    return maxCount;
}

// Test the function
int main() {
    int m;
    cin >> m;
    while(m--){
    int n;
    cin >>n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    std::cout << count_elements(arr) << std::endl;  // Output will depend on your array
    }
    return 0;
}



