int maximumPoints(vector<vector<int>>& v, int n) {
        // Code here
        // vector<vector<int>> dp(n, vector<int> (4,0));
        vector<int> curr(4,0), prev1(4,0);
        prev1[0] = max(v[0][1],v[0][2]);
        prev1[1] = max(v[0][0],v[0][2]);
        prev1[2] = max(v[0][0],v[0][1]);
        prev1[3] = max(v[0][0], max(v[0][1],v[0][2]));
        
        curr[0] = max(v[0][1],v[0][2]);
        curr[1] = max(v[0][0],v[0][2]);
        curr[2] = max(v[0][0],v[0][1]);
        curr[3] = max(v[0][0], max(v[0][1],v[0][2]));
        
        for(int i=1;i<n;i++)
        {
            for(int prev=0;prev<4;prev++)
            {
                int maxi = 0;
                
                for(int j=0;j<3;j++)
                {
                    if(prev!=j)
                    {
                        int val = v[i][j] + prev1[j];
                        maxi = max(maxi,val);
                    }
                }
                
                curr[prev] = maxi;
            }
            
            prev1 = curr;
        }
        return curr[3];
        // return fun(v,n-1,3,dp);
    }
