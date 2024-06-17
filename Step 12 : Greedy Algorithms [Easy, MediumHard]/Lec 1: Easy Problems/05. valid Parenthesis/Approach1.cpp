class Solution {
public:
    int fun(string s,int ind,int n,int cnt,vector<vector<int>> &dp)
    {
        if(cnt<0)   return 0;
        if(ind==n)
        {
            return (cnt==0);
        }

        if(dp[ind][cnt]!=-1)  return dp[ind][cnt];

        if(s[ind]=='(') return dp[ind][cnt] = fun(s,ind+1,n,cnt+1,dp);
        else if(s[ind]==')')    return dp[ind][cnt] = fun(s,ind+1,n,cnt-1,dp);
        else    return dp[ind][cnt] = (fun(s,ind+1,n,cnt+1,dp) || fun(s,ind+1,n,cnt,dp) || fun(s,ind+1,n,cnt-1,dp));
    }
    bool checkValidString(string s) {
        int n = s.length();
        int cnt = 0;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return fun(s,0,n,cnt,dp);
    }
};
