bool comp(string &a,string &b)
    {
        return (a.size() < b.size());
    }
class Solution {
public: 
    
    bool isAccept(string s1,string s2)
    {
        if(s1.size() != s2.size()  + 1) return false;

        int i = 0;
        int j = 0;

        while(i < s1.size())
        {
            if(s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        return (i==s1.length() && j==s2.length());
    }
    int fun(vector<string> &v,int n)
    {
        sort(v.begin(),v.end(),comp);
        int ans = 1;
        vector<int> dp(n,1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isAccept(v[i],v[j]))
                {
                    if(dp[i] < dp[j]+1)
                    {
                        dp[i] = dp[j]+1;
                    }
                }
                ans = max(ans,dp[i]);
            }
        }

        return ans;
    }
    int longestStrChain(vector<string>& v) {
        int n = v.size();
        return fun(v,n);
    }
};
