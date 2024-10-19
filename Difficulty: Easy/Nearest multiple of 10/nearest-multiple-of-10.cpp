//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
    int n = str.length();
    
    // Getting the last digit
    int lastDigit = str[n - 1] - '0';
    
    // If the last digit is less than or equal to 5, round down
    if (lastDigit <= 5) {
        str[n - 1] = '0';
    }
    // If the last digit is greater than 5, round up
    else {
        str[n - 1] = '0';
        int carry = 1;
        for (int i = n - 2; i >= 0; i--) {
            int num = str[i] - '0';
            int sum = num + carry;
            
            // Updating the current digit
            str[i] = '0' + sum % 10;
            carry = sum / 10;
            
            // If no carry is left, we can stop
            if (carry == 0) {
                break;
            }
        }
        
        // If there is still a carry, we need to prepend '1' to the string
        if (carry == 1) {
            str = "1" + str;
        }
    }
    
    return str;
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends