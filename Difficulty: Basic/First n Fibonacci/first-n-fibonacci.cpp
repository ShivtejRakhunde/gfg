//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long> ans;
        if(n==1) return {1};
        long long n1=1, n2=1;
        ans.push_back(n1);
        ans.push_back(n2);
        long long pt = 2;
        //
        if(n>2){
            ans.push_back(pt);
            for(int i=3; i<n; i++){
                long long temp = pt;
                pt = pt+n2;
                n2 = temp;
                ans.push_back(pt);
            }   
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends