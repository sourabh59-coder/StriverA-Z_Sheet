class Solution {
public:
    vector<int> fun(vector<int> &v,int n)
    {
        sort(v.begin(),v.end());
        vector<int> dp(n,1);
        vector<int> parent(n);
        for(int i=0;i<n;i++)    parent[i] = i;

        int ans = 1;
        int ans_ind = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[i]%v[j]==0)
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }

                if(ans < dp[i])
                {
                    ans = dp[i];
                    ans_ind = i;
                }
            }
        }

        vector<int> vec;

        while(ans_ind!=parent[ans_ind])
        {
            vec.push_back(v[ans_ind]);
            ans_ind = parent[ans_ind];
        }
        vec.push_back(v[ans_ind]);

        return vec;
    }
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n = v.size();
        return fun(v,n);
    }
};
