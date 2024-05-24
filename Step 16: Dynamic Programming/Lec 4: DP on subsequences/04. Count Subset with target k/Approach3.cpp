int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
	    
	    for(int i=0;i<=n;i++)   dp[i][0] = 1;
	    
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(arr[i] <= j)  dp[i][j] = (dp[i+1][j] + dp[i+1][j-arr[i]]) % 1000000007;
	            
	            else    dp[i][j] = dp[i+1][j] % 1000000007;
	        }
	    }
	    
	    return dp[0][sum];
	}
