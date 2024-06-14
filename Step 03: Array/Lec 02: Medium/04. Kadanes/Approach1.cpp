class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int ans = 0;
        int sum = 0;
        for(int i=0;i<v.size();i++)
        {
            sum += v[i];
            ans = max(ans,sum);
            if(sum<=0)  sum = 0;
        }
        return ans;
    }
};
