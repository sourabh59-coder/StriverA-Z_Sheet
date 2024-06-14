class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int cnt = 0;
        int ans = 0;
        int n = v.size();

        for(int i=0;i<n;i++)
        {
            if(v[i]==1) cnt++;
            else        cnt=0;

            ans = max(ans,cnt);
        }
        ans = max(ans,cnt);
        return ans;
    }
};
