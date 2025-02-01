//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool flag = false; //keeps track whether word found or not
    
    void DFS(vector<vector<char>>& mat, string& word, int r, int c, int i){
        int n1 = mat.size(), n2 = mat[0].size();
        
        //check if out of bound
        if(r<0 || c<0 || r>=n1 || c>=n2){
            return;
        }
        
        //if character matches
        if(word[i] == mat[r][c]){
            //if all chars of word found
            if(word.size()-1 == i){
                flag = true;
                return;
            }
            
            char s = mat[r][c]; //current charcter
            mat[r][c] = 'v'; //mark current cell as visited
            
            //search in all possible directions
            DFS(mat, word, r-1, c, i+1);
            DFS(mat, word, r+1, c, i+1);
            DFS(mat, word, r, c-1, i+1);
            DFS(mat, word, r, c+1, i+1);
            
            mat[r][c] = s; //reset cell to its original value
        }
        return;
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int r = mat.size(), c = mat[0].size();
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                //if initial character of word found then search DFS from it
                if(mat[i][j] == word[0]){
                    DFS(mat, word, i, j, 0);
                }
            }
        }
        return flag;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends