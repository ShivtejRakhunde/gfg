//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isPossible(vector<vector<int>> &mat, int crow, int ccol, int val) {
        for (int i = 0; i < 9; i++) {
            if (mat[crow][i] == val || mat[i][ccol] == val) {
                return false;
            }
        }
        int startRow = 3 * (crow / 3);
        int startCol = 3 * (ccol / 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[startRow + i][startCol + j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool helper(vector<vector<int>> &mat) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (mat[i][j] == 0) {
                    for (int k = 1; k <= 9; k++) {
                        if (isPossible(mat, i, j, k)) {
                            mat[i][j] = k;
                            if (helper(mat)) {
                                return true;
                            }
                            mat[i][j] = 0; // Backtrack
                        }
                    }
                    return false; //No valid number found need to backtrack
                }
            }
        }
        return true; //Sudoku completely filled
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        helper(mat);
    }
    
    void printMat(const vector<vector<int>> &mat) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends