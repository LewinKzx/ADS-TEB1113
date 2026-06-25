#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// Function to find the submatrix of order k * k with maximum sum of elements
int maximumSum(vector<vector<int>> &mat, int k) {
    int n = mat.size();

    int ans = INT_MIN; // store the answer

    // generate all possible submatrix of order k * k
    for(int i = 0; i <= n - k; i++) {
        for(int j = 0; j <= n - k; j++) {

            // compute sum of submatrix of order k * k
            int sum = 0;
            for(int p = i; p < i + k; p++) {
                for(int q = j; q < j + k; q++) {
                    sum += mat[p][q];
                }
            }

            // update the maximum sum
            ans = max(ans, sum);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> mat = { 
    { 1, 2, -1, 4 },
    { -8, -3, 4, 2 },
    { 3, 8, 10, -8 },
    { -4, -1, 1, 7 } };
    int k = 3;
    cout << maximumSum(mat, k); //display result
    return 0;
}