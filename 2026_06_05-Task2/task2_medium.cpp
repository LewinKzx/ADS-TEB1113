// C++ program to find Diagonal Traversal of a Matrix
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function that returns elements of given mat in diagonal order
vector<int> DiagonalOrder(const vector<vector<int>>& mat) { // 2D matrix into 1D vector, const = read only, & for pass by reference
    vector<int> res;
    
    int n = mat.size(); //matrix rows
    int m = mat[0].size(); //matrix columns
    
    // There will be n+m-1 diagonals in total
    for(int line = 1; line <= (n + m - 1); line++) {
        
        // Get column index of first element in diagonal. Index is 0 for first n lines and (line - n) for remaining lines
        int startCol = max(0, line - n);
        
        // Get count of elements in diagonal and count equals minimum of line number, (m-startCol) and n
        int count = min({line, (m - startCol), n});
        
        // Process elements of this diagonal
        for(int j = 0; j < count; j++) {
            
            // Calculate row and column indices for each element in the diagonal
            int row = min(n, line) - j - 1;
            int col = startCol + j;
            res.push_back(mat[row][col]); //res store the elements of the diagonal in the result vector
        }
    }
    
    return res;
}

int main() {

    vector<vector<int>> mat = {
        { 1, 6, 11, 16 },
        { 2, 7, 12, 17 },
        { 3, 8, 13, 18 },
        { 4, 9, 14, 19 },
        { 5, 10, 15, 20 }
    };
    vector<int> res = DiagonalOrder(mat);
    for (auto val: res) cout << val << " "; //displaying elements
    cout << endl;
    
    return 0;
}