class Solution {
public:
    vector<vector<int>> LongestCommon(string s1,string s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])     dp[i][j] = (1 + dp[i-1][j-1]);

                else                 dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }

        return dp;
    }
    string shortestCommonSupersequence(string s1, string s2) {
        vector<vector<int>> dp = LongestCommon(s1,s2);
        int n = s1.size();
        int m = s2.size();

        string ans = "";

        int i = n, j = m;

        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1])
                {
                    ans.push_back(s1[i-1]);
                    i--;
                    j--; 
                }

                else if(dp[i-1][j] >= dp[i][j-1])
                {
                    ans.push_back(s1[i-1]);
                    i--;
                }

                else
                {
                    ans.push_back(s2[j-1]);
                    j--;
                }
        }

        while(i>0)
        {
            ans.push_back(s1[i-1]);
            i--;
        }

        while(j>0)
        {
            ans.push_back(s2[j-1]);
            j--;
        }


        reverse(ans.begin(),ans.end());

        // cout<<ans<<endl;

        return ans;
    }
};
