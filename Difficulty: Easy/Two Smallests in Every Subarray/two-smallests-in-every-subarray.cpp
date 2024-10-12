//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n<2){
            return -1;
        }
        
        int maxSum = arr[0] + arr[1];  
        // Initialize with the sum of the first adjacent pair

        // Iterate through the array and calculate the sum of adjacent pairs
        for (int i = 1; i < n - 1; i++) {
            int currentSum = arr[i] + arr[i + 1];  // Sum of adjacent elements
            maxSum = max(maxSum, currentSum);  // Update the maximum sum
        }
    
        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends