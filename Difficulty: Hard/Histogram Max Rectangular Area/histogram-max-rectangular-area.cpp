//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int maxArea = 0, height = 0, width = 0;
        stack<int> st;
        
        for(int i=0; i<=arr.size(); i++){
            height = (i==arr.size())? 0: arr[i]; //for last nth index height is 0
            
            while(!st.empty() && height<arr[st.top()]){ //if current height is smaller
                int h = arr[st.top()];  // Get height of top element
                st.pop();               // Remove from stack
                
                width = st.empty() ? i : i - st.top() - 1; // Compute width
                maxArea = max(maxArea, h * width);  // Update max area
            }
            st.push(i);
        }
        return maxArea;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends