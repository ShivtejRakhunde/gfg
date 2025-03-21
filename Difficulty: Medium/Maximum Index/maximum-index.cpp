//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // arr[]: input array
    // Function to find the maximum index difference.
    int maxIndexDiff(vector<int>& arr) {
        // Your code here
        int ans = 0;
        int n = arr.size();
        
        vector<int> minE(n), maxE(n);
        
        minE[0] = arr[0];
        for(int i=1; i<n; i++){
            minE[i] = min(minE[i-1],arr[i]);
        }
        
        maxE[n-1] = arr[n-1];
        for(int j=n-2; j>=0; j--){
            maxE[j] = max(maxE[j+1],arr[j]);
        }
        
        int i=0, j=0;
        while(i<n && j<n){
            if(minE[i]<=maxE[j]){
                ans = max(ans,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(nums) << endl;
    }

    return 0;
}
// } Driver Code Ends