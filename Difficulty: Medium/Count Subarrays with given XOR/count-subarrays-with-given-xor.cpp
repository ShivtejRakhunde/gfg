//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int xorSum = 0;
    long subarr = 0;

    for (int num : arr) {
        // Update XOR sum
        xorSum ^= num;

        // Check if XOR of current subarray equals k
        if (xorSum == k) {
            subarr++;
        }

        // Check if there's a prefix XOR such that prefixXor ^ k = xorSum
        int target = xorSum ^ k;
        if (freq.find(target) != freq.end()) {
            subarr += freq[target];
        }

        // Update the frequency map
        freq[xorSum]++;
    }

    return subarr;
}

};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends