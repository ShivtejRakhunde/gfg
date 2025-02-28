//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<long long> st;
        
        for(string& c: arr){
            if(c!="+" && c!="-" && c!="*" && c!="/"){
                st.push(stoll(c));
            }
            else{
                long long x = st.top();
                st.pop();
                long long y = st.top();
                st.pop();
                
                if(c == "+"){
                    st.push(y+x);
                }
                else if(c == "-"){
                    st.push(y-x);
                }
                else if(c == "*"){
                    st.push(x*y);
                }
                else{
                    st.push(y/x);
                }
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends