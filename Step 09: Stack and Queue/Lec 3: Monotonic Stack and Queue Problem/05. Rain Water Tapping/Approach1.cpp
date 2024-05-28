class Solution {
public:
    int trap(vector<int>& v) {
        int ans = 0;
        int n = v.size();
        vector<int> rm(n);
        rm[0] = v[0];

        vector<int> lm(n);
        lm[n-1] = v[n-1];

        for(int i=1;i<n;i++)        rm[i] = max(v[i],rm[i-1]);

        for(int i=n-2;i>=0;i--)     lm[i] = max(v[i],lm[i+1]);

        for(int i=1;i<n-1;i++)
        {
            int val = min(rm[i],lm[i]);
            ans += abs(val-v[i]);
        }

        return ans;
    }
};
