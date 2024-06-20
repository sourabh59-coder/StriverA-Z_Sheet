class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int fun(string s,int i,int n,vector<int> &dp)
    {
        if(i==n)  return 0;

        if(dp[i]!=-1)   return dp[i];

        int maxi = INT_MAX;

        string temp = "";

        for(int k=i;k<n;k++)
        {
            temp.push_back(s[k]);
            if(isPalindrome(i, k, s))
            {
                int cost = 1+fun(s,k+1,n,dp);
                maxi = min(maxi,cost);
            }
        }

        return dp[i] = maxi;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return fun(s,0,n,dp)-1;
    }
};
