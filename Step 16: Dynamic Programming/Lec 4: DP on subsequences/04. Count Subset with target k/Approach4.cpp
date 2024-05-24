int perfectSum(int arr[], int n, int sum)
	{
	   // vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
	   vector<int> curr(sum+1, 0);
	   vector<int> next(sum+1, 0);
	    
	    curr[0] = 1;
	    next[0] = 1;
	    
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(arr[i] <= j)  curr[j] = (next[j] + next[j-arr[i]]) % 1000000007;
	            
	            else    curr[j] = next[j] % 1000000007;
	        }
	        next = curr;
	    }
	    
	    return curr[sum];
	}
