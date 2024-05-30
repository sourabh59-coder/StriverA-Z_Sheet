class Solution {
public:
    int maxProfit(vector<int>& v) {
        int ans = 0;
        int n = v.size();
        int mval = v[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ans = max(ans,mval-v[i]);
            mval = max(mval,v[i]);
        }
        return ans;
    }
};
