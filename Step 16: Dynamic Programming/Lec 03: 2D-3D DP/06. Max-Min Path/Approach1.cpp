class Solution {
public:
    int fun(vector<vector<int>> &v,int i,int j,int n,int m)
    {
        if(j<0 || j>=m)     return 1e9;
        if(i==n-1)  return v[i][j];
        

        int a = v[i][j] + fun(v,i+1,j,n,m);
        int b = v[i][j] + fun(v,i+1,j-1,n,m);
        int c = v[i][j] + fun(v,i+1,j+1,n,m);

        return min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        int maxi = 1e9;
        for(int j=0;j<m;j++)
        {
            maxi = min(maxi , fun(v,0,j,n,m));
        }
        return maxi;
    }
};
