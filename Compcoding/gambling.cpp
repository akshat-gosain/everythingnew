#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;

    while(m--) {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> matrix(rows, vector<int>(cols));

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                cin >> matrix[i][j];
            }
        }

        int sum = 0;
        for(int j = 0; j < cols; ++j) {
            for(int i = 0; i < rows - 1; ++i) {
                for(int k = i + 1; k < rows; ++k) {
                    sum += abs(matrix[i][j] - matrix[k][j]);
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}

