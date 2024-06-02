class Solution {
public:
    int fun(vector<vector<int>> &v,int n,int m)
    {
        if(m<0 || m>=v[0].size())   return 1e9;
        
        if(n==0)    return v[0][m];

        int a = v[n][m] + fun(v,n-1,m);
        int b = v[n][m] + fun(v,n-1,m-1);
        int c = v[n][m] + fun(v,n-1,m+1);
        
        return min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size(),m = v[0].size();
        int mini = 1e9;

        for(int i=0;i<m;i++)
        {
            mini = min(mini, fun(v,n-1,i));
        }
        
        return mini;
    }
};
