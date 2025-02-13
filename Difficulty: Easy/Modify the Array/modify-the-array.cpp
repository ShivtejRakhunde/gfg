//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            if(arr[i]!=0 && arr[i+1]!=0){
                if(arr[i]==arr[i+1]){
                    arr[i] *= 2;
                    arr[i+1] = 0;
                }
            }
        }
        
        vector<int> vt;
        
        for(int c: arr){
            if(c != 0){
                vt.push_back(c);
            }
        }
        
        int zero = n - vt.size();
        
        for(int i=0; i<zero; i++){
            vt.push_back(0);
        }
        
        return vt;
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends