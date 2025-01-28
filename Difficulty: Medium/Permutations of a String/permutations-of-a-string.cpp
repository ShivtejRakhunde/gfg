//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(vector<string> &ans, string s, int index, string &t, int &n){
        if(index>=n){
            ans.push_back(t);
            return;
        }
        
        for(int i=0; i<s.size(); i++){
            if(i>0 && s[i]==s[i-1]){
                continue;
            }
            t = t + s[i];
            solve(ans, s.substr(0,i) + s.substr(i+1), index+1, t, n);
            t.pop_back();
        }
    }
    
    vector<string> findPermutation(string &s) {
        // Code here there
        sort(s.begin(), s.end());
        string t = "";
        int n = s.length();
        vector<string> ans;
        solve(ans, s, 0, t, n);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends