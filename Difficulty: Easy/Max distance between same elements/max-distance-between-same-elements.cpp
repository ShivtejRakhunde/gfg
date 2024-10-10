//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> mp;
        int ans = -1; 
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            (mp.find(arr[i]) == mp.end()) ? mp[arr[i]] = i + 1 : ans = max(ans, abs(i+1 - mp[arr[i]]));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends