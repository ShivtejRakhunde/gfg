//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        int n = s.size();
        if(n==0) return s; //return as it is if contains nothing
        
        stack<int> num; //stores the num or k
        stack<string> st; //stores rest [ or abc...
        string ans = ""; //conatins final result
        
        int tempnum = 0; //stores num like 123
        
        for(char c: s){
            if(isdigit(c)){
                tempnum = tempnum*10 + (c - '0'); //converts digits to
            }
            else if(c == '['){
                num.push(tempnum);
                tempnum = 0;
                st.push(ans);
                ans = "";
            }
            else if(c == ']'){
                int k = num.top();
                num.pop();
                string curans = st.top();
                st.pop();
                
                for(int j=0; j<k; j++){
                    curans += ans;
                }
                ans = curans;
            }
            else{
                ans += c;
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
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends