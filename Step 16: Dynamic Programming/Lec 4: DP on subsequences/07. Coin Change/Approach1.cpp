class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int k)
    {
        if(ind==n)
        {
            if(k==0)    return 0;
            else        return 1e9;
        }

        int notTake = 0 + fun(v,ind+1,n,k);

        int Take = INT_MAX;

        if(k >= v[ind])     Take = 1 + fun(v,ind,n,k-v[ind]);

        return min(Take,notTake);
    }
    int coinChange(vector<int>& v, int k) {
        int n = v.size();
        int res = fun(v,0,n,k);
        return (res >= 1e9) ? -1:res;
    }
};
