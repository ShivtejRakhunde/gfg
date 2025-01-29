//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        if (e == 0) return 1.0;
    
        double ans = 1.0;
        long long exp = abs(e);
    
        while (exp > 0) {
            if (exp % 2 == 1) {  //If exponent is odd, multiply result by base
                ans *= b;
            }
            b *= b;  // Square the base
            exp /= 2;  // Divide the exponent by 2
        }
    
        return (e < 0) ? 1.0 / ans : ans;  // Handle negative exponents
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends