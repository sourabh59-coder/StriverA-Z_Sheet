int LongestBitonicSequence(int n, vector<int> &v) {
        // code here
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[j] < v[i])
                {
                    dp1[i] = max(dp1[i],dp1[j] + 1);
                }
                
            }
            
            // cout<<dp1[i]<<" ";
            
        }
        // cout<<endl;
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(v[j] < v[i])
                {
                    dp2[i] = max(dp2[i],dp2[j]+1);
                }
                
            }
            // cout<<dp2[i]<<" ";
            
        }
        
        // cout<<endl;
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(dp1[i]!=1 && dp2[i]!=1)
            {
                int val = dp1[i] + dp2[i] - 1;
                ans = max(ans,val);
            }
        }
        
        return ans;
    }
