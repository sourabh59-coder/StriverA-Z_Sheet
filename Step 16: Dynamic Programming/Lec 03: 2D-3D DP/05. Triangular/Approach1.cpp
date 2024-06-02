class Solution {
public:
    int fun(vector<vector<int>> &v,int i,int j,int n)
    {
        if(i==n-1)
        {
            return (v[i][j]);
        }

        return min(v[i][j] + fun(v,i+1,j,n) , v[i][j] + fun(v,i+1,j+1,n));
    }
    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();
        return fun(v,0,0,n);
    }
};
