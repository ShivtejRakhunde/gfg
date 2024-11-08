//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        string temp = s1;
        int k = 1;
        while(s1.length()<s2.length()){
            s1 += temp;
            k++;
        }
        
        if(s1.find(s2)!=-1){
            return k;
        }
        
        //do one more time to ensure accuracy
        s1 += temp;
        k++;
        
        if(s1.find(s2)!=-1){
            return k;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends