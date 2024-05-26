class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int k)
    {
        if(ind==n)
        {
            if(k==0)    return 1;
            else        return 0;
        }

        int notTake = fun(v,ind+1,n,k-v[ind]);

        int Take = fun(v,ind+1,n,k+v[ind]);

        return (notTake + Take);
    }
    int findTargetSumWays(vector<int>& v, int k) {
        int n = v.size();
        return fun(v,0,n,k);
    }
};
