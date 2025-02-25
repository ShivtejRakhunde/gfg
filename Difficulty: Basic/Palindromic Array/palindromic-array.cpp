//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*Complete the function below*/

class Solution {
  public:
    bool checkPalindrome(int n){
        int digit = 0, sum = 0, temp = n;
        while(n>0){
            digit = n%10;
            sum = sum*10 + digit;
            n /= 10;
        }
        if(temp == sum) return true;
        return false;
    }
    bool isPalinArray(vector<int> &arr) {
        // code here
        for(int num: arr){
            if(!checkPalindrome(num)){
                return false;
            }
        }
        return true;;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        cout << (ob.isPalinArray(arr) ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends