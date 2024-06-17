class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        double pref = 1, suff = 1;
        double ans = INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(pref==0) pref = 1;
            if(suff==0) suff = 1;

            pref *= v[i];
            suff *= v[n-1-i];

            ans = max(ans,max(pref,suff));
        }

        return (int)ans;
    }
};
