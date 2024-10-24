//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        // code here
        vector<int> ans;
        
        if (M <= 2 && N >= 2) {
            ans.push_back(2);
        }
        
        if (M < 3) M = 3;
        if (M % 2 == 0) M++;
        
        for (int i = M; i <= N; i += 2) {
            bool isPrime = true;
            
            for (int j = 3; j <= sqrt(i); j += 2) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            
            if (isPrime) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends