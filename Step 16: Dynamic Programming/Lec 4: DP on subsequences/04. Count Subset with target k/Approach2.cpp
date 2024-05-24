int fun(int arr[],int ind,int n,int sum, vector<vector<int>> &dp)
	{
	   // if(sum==0)  return 1;
	    
	    if(ind==n)
	    {
	        if(sum==0)  return 1;
	        else    return 0;
	    }
	    
	    if(dp[ind][sum]!=-1)    return dp[ind][sum];
	    
	    if(arr[ind] <= sum)   return dp[ind][sum] = (fun(arr,ind+1,n,sum,dp) + fun(arr,ind+1,n,sum-arr[ind],dp)) % 1000000007;
	    
	    else    return dp[ind][sum] = (fun(arr,ind+1,n,sum,dp)) % 1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return fun(arr,0,n,sum,dp);
	}
