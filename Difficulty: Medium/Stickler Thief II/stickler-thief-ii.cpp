//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxRob(vector<int>& arr, int start, int end){
        int t1 = 0, t2 = 0;
        
        for(int i=start; i<end; i++){
            int Rob = arr[i];
            int DontRob = t1;
            
            if(i>1){
                Rob += t2;
            }
            t2 = t1;
            t1 = max(Rob,DontRob);
        }
        return t1;
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        return max(maxRob(arr,0,n-1),maxRob(arr,1,n));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends