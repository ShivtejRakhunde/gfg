//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        long long ans = 0;
        
        while(N%2==0){
            ans = 2;
            N = N/2;
        }
        
        for(long long i=3; i<=sqrt(N); i+=2){
            while(N%i==0){
                ans = i;
                N = N/i;
            }           
        }
        
        if(N>2){
            ans = N;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends