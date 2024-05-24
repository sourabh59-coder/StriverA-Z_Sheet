class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        // vector<vector<int>> dp(n+3, vector<int> (2,0));
        vector<int> next(2,0), nextnext(2,0), curr(2,0);

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(j)     curr[j] = max((0+next[j]),(-v[i]+next[1-j]));

                else       curr[j] = max((0+next[j]),(+v[i]+nextnext[1-j]));
            }

            nextnext = next;
            next = curr;
        }

        return curr[1];
    }
};
