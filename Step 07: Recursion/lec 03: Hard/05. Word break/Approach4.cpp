class Solution {
public:
    // int fun(string &s,int ind,int n,unordered_set<string> &st,vector<int> &dp)
    // {
    //     if(ind==n)
    //     {
    //         return 1;
    //     }

    //     if(dp[ind]!=-1)   return dp[ind];

    //     int ans = 0;
    //     for(int i=ind;i<n;i++)
    //     {
    //         string check = s.substr(ind,i-ind+1);
    //         if(st.count(check))
    //         {
    //             ans  |= fun(s,i+1,n,st,dp);
    //         }
    //     }

    //     return dp[ind] = ans;
    // }
    bool wordBreak(string s, vector<string>& vec) {
        unordered_set<string> st;
        for(int i=0;i<vec.size();i++)
        {
            st.insert(vec[i]);
        }
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[n] = 1;

        for(int j=n-1;j>=0;j--)
        {
            int ans = 0;
            for(int i=j;i<n;i++)
            {
                string check = s.substr(j,i-j+1);
                if(st.count(check))
                {
                    ans  |= dp[i+1];
                }
            }

            dp[j] = ans;
        }

        return dp[0];
        // // bool ans = false;
        // return fun(s,0,n,st,dp);
    }
};
