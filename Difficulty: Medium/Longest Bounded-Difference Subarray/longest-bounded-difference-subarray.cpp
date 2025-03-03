//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        multiset<int> st; //keeps current windows elements in ascending order
        int l = 0, r = 0; //pointers to current window
        int maxlen = 0; //to store longest subarray found
        int ind = 0; //stores the start index
        
        while(r<arr.size()){ //
            st.insert(arr[r]); //add element to multiset
            
            // If the difference between the max and min values exceeds x, adjust the left pointer
            while (*st.rbegin() - *st.begin() > x) {  
                st.erase(st.find(arr[l]));  // Remove the leftmost element from the multiset
                l++;  // Move the left pointer to shrink the window
            }
            
            // Calculate the current valid window length
            int len = r - l + 1;
            if (maxlen < len) {  // Update maxlen and starting index if this window is the longest
                maxlen = len;
                ind = l;
            }
            
            r++; //increment right pointer
        }
        
        // Return the longest valid subarray
    return vector<int>(arr.begin() + ind, arr.begin() + ind + maxlen);
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends