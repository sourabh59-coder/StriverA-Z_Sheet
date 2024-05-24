class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<int> next(2), curr(2);

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                long long profit;
                if(j==1)
                {
                    profit = max( 0+next[1] , -v[i]+next[0]);
                }
                else
                {
                    profit = max( 0+next[0] , v[i]+next[1]);
                }
                curr[j] = profit;
            }
            next = curr;
        }

        return curr[1];
    }
};
