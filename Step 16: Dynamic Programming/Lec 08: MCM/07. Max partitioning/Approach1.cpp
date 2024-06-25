class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int k)
    {
        if(ind==n)  return 0;

        int ans = INT_MIN;
        int maxi = INT_MIN;
        int len = 0;
        for(int i=ind;i<min(n,ind+k);i++)
        {
            len++;
            maxi = max(maxi,v[i]);
            int val = (maxi*len) + fun(v,i+1,n,k);
            ans = max(ans,val);
        }
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        return fun(v,0,n,k);
    }
};
