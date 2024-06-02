class Solution {
public:
    int fun(vector<vector<int>> &v,int n,int m)
    {
        if(n<0 || m<0 || v[n][m]==1)    return 0;
        if(n==0 && m==0)    return 1;
        

        int left = fun(v,n-1,m);
        int right = fun(v,n,m-1);

        return (left + right);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        return fun(v,n-1,m-1);
    }
};
