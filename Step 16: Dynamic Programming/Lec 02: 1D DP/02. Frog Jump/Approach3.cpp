// int fun(vector<int> &v,int ind,int n,vector<int> &dp)
    // {
    //     if(ind==n-1)  return 0;
        
    //     // if(ind>n)   return INT_MAX;
        
    //     if(dp[ind]!=-1) return dp[ind];
        
    //     int one = fun(v,ind+1,n,dp) + abs(v[ind]-v[ind+1]);
        
    //     int two = INT_MAX;
        
    //     if(ind <= (n-3))    two = fun(v,ind+2,n,dp) + abs(v[ind]-v[ind+2]); 
        
    //     return dp[ind] = min(one,two);
    // }
    int minimumEnergy(vector<int>& v, int n) {
        // Code here
        // vector<int> dp(n,-1);
        // return fun(v,0,n,dp);
        
        // vector<int> dp(n,0);
        
        int curr(0), next(0), next_next(0);
        
        for(int i=n-2;i>=0;i--)
        {
            int one = next + abs(v[i]-v[i+1]);
            
            int two = INT_MAX;
            
            if(i <= n-3)    two = next_next + abs(v[i]-v[i+2]);
            
            curr = min(one,two);
            
            next_next = next;
            next = curr;
        }
        
        return curr;
    }
