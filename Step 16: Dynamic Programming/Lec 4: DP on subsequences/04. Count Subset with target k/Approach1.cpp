int fun(int arr[],int ind,int n,int sum)
	{
	   // if(sum==0)  return 1;
	    
	    if(ind==n)
	    {
	        if(sum==0)  return 1;
	        else    return 0;
	    }
	    
	    if(arr[ind] <= sum)   return (fun(arr,ind+1,n,sum) + fun(arr,ind+1,n,sum-arr[ind]));
	    
	    else    return (fun(arr,ind+1,n,sum));
	}
	int perfectSum(int arr[], int n, int sum)
	{
        return fun(arr,0,n,sum);
	}
