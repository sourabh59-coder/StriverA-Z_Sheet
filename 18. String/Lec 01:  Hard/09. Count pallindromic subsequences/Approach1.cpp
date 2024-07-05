//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long fun(string &s,int l,int r,vector<vector<long long int>> &dp)
    {
        int mod = (int)(1e9+7);
        if(l>r) return 0;
        if(l==r)    return 1;
        
        if(dp[l][r]!=-1)    return dp[l][r];
        
        if(s[l]==s[r])  dp[l][r] = (1 + fun(s,l+1,r,dp) + fun(s,l,r-1,dp))%mod;
        
        else            dp[l][r] = (((fun(s,l+1,r,dp)+fun(s,l,r-1,dp))%mod-fun(s,l+1,r-1,dp)+mod)%mod)%mod;
        
        return dp[l][r];
    }
    long long int  countPS(string str)
    {
       //Your code here
       int n  = str.size();
       vector<vector<long long int>> dp(n, vector<long long int> (n,-1));
       return fun(str,0,n-1,dp);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends
