//4x4 square matrix rotate elements clockwise by one step.
#include <iostream>
#include <vector> // For matrix
using namespace std;

// Function to rotate a matrix represented by a vector of vectors
void RotateMatrix(vector<vector<int>>& mat) { // vector<vector<int>> = For vector in vector like 2D array
  
    int m = mat.size(); // Number of rows in matrix
    int n = mat[0].size(); // Number of columns in matrix by index
  
    int row = 0, col = 0;
    int prev, curr; // To store the previous and current elements by index

    // Rotate the matrix in layers
    while (row < m && col < n) { // Checks twice as row & col ++ while m & n -- 
        if (row + 1 == m || col + 1 == n) 
            break;

        // Store the first element to move : 5 into position of 1
        prev = mat[row + 1][col];

        // Move elements of the first row
        for (int i = col; i < n; i++) { //col = 0, n = 4
            curr = mat[row][i]; // Store the current element
            mat[row][i] = prev; // Replace current element with previous(5)
            prev = curr; // Change previous to current for next iteration 5 = 1
        }
        row++;

        // Move elements of the last column
        for (int i = row; i < m; i++) { //row = 1, m = 4
            curr = mat[i][n - 1]; //curr = mat[1][3] = 8
            mat[i][n - 1] = prev; //mat[1][3] = 4
            prev = curr; //prev = 8
        }
        n--;

        // Move elements of the last row
        if (row < m) {
            for (int i = n - 1; i >= col; i--) {
                curr = mat[m - 1][i];
                mat[m - 1][i] = prev;
                prev = curr;
            }
        }
        m--;

        // Move elements of the first column
        if (col < n) {
            for (int i = m - 1; i >= row; i--) {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }
}

int main() {
    vector<vector<int>> mat = { // Initialize the matrix
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    RotateMatrix(mat);

    // Print the rotated matrix
    for (auto& r : mat) { // For each row in the matrix
        for (int val : r) // For each value in the row
            cout << val << " ";
        cout << endl;
    }

    return 0;
}