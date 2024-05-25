class Solution {
public:
    // int fun(int ind, vector<int> &dp)
    // {
    //     if(ind==0)    return 1;

    //     if(dp[ind]!=-1) return dp[ind];

    //     int one = fun(ind-1,dp);
    //     int two = 0;
    //     if(ind>=2)  two = fun(ind-2,dp);

    //     return dp[ind] = (one+two);
    // }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return fun(n,dp);

        // vector<int> dp(n+1, 0);
        // dp[0] = 1;

        int prev = 1;
        int prev2 = 0;
        int curr = 0;

        for(int i=1;i<=n;i++)
        {
            int one = prev;

            int two = 0;
            if(i>=2)    two = prev2;

            curr = (one + two);

            prev2 = prev;
            prev = curr;
        }

        return curr;
    }
};
