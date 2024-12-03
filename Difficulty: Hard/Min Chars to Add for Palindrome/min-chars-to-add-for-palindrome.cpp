//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
    int minChar(string& s) {
        // Write your code here
        int n = s.size();
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        string join = s+"#"+rs;
        
        int m = join.size();
        vector<int> ans(m,0);
        
        for(int i=1; i<m; i++){
            int l = ans[i-1];
            while(l>0 && join[i]!=join[l]){
                l = ans[l-1];
            }
            if(join[i]==join[l]){
                l++;
            }
            ans[i] = l;
        }
        return n-ans[m-1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends