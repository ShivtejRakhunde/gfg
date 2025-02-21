//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        if(s.size()<=1){
            return false;
        }
        stack<char> st;
        
        for(char c: s){
            if(c=='[' || c=='{' || c=='('){
                st.push(c);
            }
            else if(st.empty()){
                return false;
            }
            else{
                if(c==']'){
                    if(st.top()!='['){
                        return false;
                    }
                }
                if(c=='}'){
                    if(st.top()!='{'){
                        return false;
                    }
                }
                if(c==')'){
                    if(st.top()!='('){
                        return false;
                    }
                }
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends