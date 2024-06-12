//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int fun(int arr[],int ind,int n,int sum,vector<vector<int>>  &dp)
	{
	    if(ind==n)
	    {
	        if(sum==0)  return 1;
	        else        return 0;
	    }
	    
	    if(dp[ind][sum]!=-1)    return dp[ind][sum];
	    
	    int l = 0, r = 0;
	    
	    //notTake
	    l = fun(arr,ind+1,n,sum,dp);
	    
	    //Take
	    if(arr[ind]<=sum)    r = fun(arr,ind+1,n,sum-arr[ind],dp);
	    
	    return dp[ind][sum] = (l+r) % 1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>  dp(n+1, vector<int> (sum+1,-1));
        return fun(arr,0,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
