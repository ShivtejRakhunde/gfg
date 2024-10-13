//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sortIt(vector<long long>& arr) {
        // code here.
        vector<long long> ans;
        vector<long long> odd;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0){
                ans.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
        }
        
        sort(odd.begin(),odd.end(),greater<int>());
        sort(ans.begin(),ans.end());
        
        arr.clear();
        arr.insert(arr.end(), odd.begin(), odd.end());
        arr.insert(arr.end(), ans.begin(), ans.end());
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.sortIt(arr);

        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends