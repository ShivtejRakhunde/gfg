//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
        
        int n;
        vector<int> ans;
        vector<int> visited;
        
    void DFS(int i, vector<vector<int>>& adj){
        visited[i] = 1;
        ans.push_back(i);
        
        for(auto &node: adj[i]){
            if(!visited[node]){
                DFS(node, adj);
            }
        }
    }
        
    vector<int> dfs(vector<vector<int>>& adj) {
        n = adj.size();
        
        visited.resize(n, 0);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                DFS(i, adj);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends