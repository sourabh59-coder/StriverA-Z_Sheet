class Solution {
public:
    int fun(vector<int> &v,int goal)
    {
        if(goal<0)  return 0;
        int l = 0, r = 0, ans = 0;
        int sum = 0;
        int n = v.size();
        while(r<n)
        {
            if(v[r]%2==1)   sum++;

            while(sum > goal)
            {
                if(v[l]%2==1)    sum--;
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& v, int k) {
        return fun(v,k) - fun(v,k-1);
    }
};
