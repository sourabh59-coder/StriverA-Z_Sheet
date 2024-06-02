class Solution {
public:
    int fun(vector<vector<int>> &v,int n,int m)
    {
        if(n==0 && m==0)    return v[0][0];
        if(n<0 || m<0)  return 1e9;

        int left(0),right(0);

        left = v[n][m] + fun(v,n-1,m);

        right = v[n][m] + fun(v,n,m-1);

        return min(left,right);
    }
    int minPathSum(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        return fun(v,n-1,m-1);
    }
};
