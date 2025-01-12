//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n==0) return 0;
        
        int l = 0, r = n - 1; // Pointers to traverse the array
        int lx = 0, rx = 0; // To store the maximum height to the left and right
        int twr = 0;
        
        while(l<=r){
            if(arr[l]<=arr[r]){
                if(arr[l]>=lx){
                    lx = arr[l];
                }
                else{
                    twr += lx - arr[l]; //water trapped at current block
                }
                l++;
            }
            else{
                if(arr[r]>=rx){
                    rx = arr[r];
                }
                else{
                    twr += rx - arr[r]; //water trapped at current block
                }
                r--;
            }
        }
    
        return twr;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends