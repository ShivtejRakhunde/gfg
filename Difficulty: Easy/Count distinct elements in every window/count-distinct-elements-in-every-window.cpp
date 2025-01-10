//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n = arr.size();
        int i=0,j=0;
        
        map<int,int> mp;
        vector<int> ans;
        
        while(j<n)
        {
            mp[arr[j]]++;
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                ans.push_back(mp.size());
                if(mp[arr[i]] == 1)
                {
                    mp.erase(arr[i]);
                }
                else
                {
                    mp[arr[i]]--;
                }
                i++;j++;
            }
        }
        return ans;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends