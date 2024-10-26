//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       int n = s1.size();
        int m = s2.size();
        
        // If either number is "0", the result is "0"
        if (s1 == "0" || s2 == "0") return "0";
        
        // Determine the sign of the result
        bool isNegative = false;
        if (s1[0] == '-') {
            isNegative = !isNegative;
            s1 = s1.substr(1); // Remove the negative sign
            n--;
        }
        if (s2[0] == '-') {
            isNegative = !isNegative;
            s2 = s2.substr(1); // Remove the negative sign
            m--;
        }
        
        // Result vector to hold the product
        vector<int> v(n + m, 0);
        
        // Multiply each digit of s1 and s2
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = v[i + j + 1] + mul;
                v[i + j + 1] = sum % 10;
                v[i + j] += sum / 10;
            }
        }
        
        // Convert the vector result to a string
        string ans;
        
        // Add the negative sign if necessary
        if (isNegative) {
            ans = "-";
        }
        
        // Skip leading zeros
        int i = 0;
        while (i < n + m && v[i] == 0) {
            i++;
        }
        
        // If there are no digits left after leading zeros, return "0"
        if (i == n + m) return "0";
        
        // Append the remaining digits to the result
        while (i < n + m) {
            ans += to_string(v[i++]);
        }
        
        return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    
cout << "~" << "\n";
}
     
}
// } Driver Code Ends