//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void SetRowZero(vector<vector<int>> &mat, int r){
        for(int i=0; i<mat[r].size(); i++){
            mat[r][i] = 0;
        }
    }
    
    void SetColZero(vector<vector<int>> &mat, int c){
        for(int j=0; j<mat.size(); j++){
            mat[j][c] = 0;
        }
    }
  
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        vector<int> rows, cols;
        
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j]==0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        for(int r : rows){
            SetRowZero(mat, r);
        }
        
        for(int c : cols){
            SetColZero(mat, c);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends