class Solution {
public:
    int fun(vector<int> &v,int goal)
    {
        if(goal<0) return 0;
        long long l=0,r=0,sum=0,ans=0;
        int n = v.size();
        while(r<n)
        {
            sum += v[r];
            while(sum > goal)
            {
                sum -= v[l];
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& v, int goal) {
        return (fun(v,goal) - fun(v,goal-1));
    }
};
