class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int k = 2;
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2 , vector<int> (4)));
        vector<vector<int>> curr(2, vector<int> (3,0)), next(2, vector<int> (3, 0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=1;k<=2;k++)
                {
                    if(j==1)
                    {
                        curr[j][k] = max((0+next[j][k]),(-v[i]+next[1-j][k]));
                    }

                    else
                    {
                        curr[j][k] = max((0+next[j][k]),(v[i]+next[1-j][k-1]));
                    }
                }
            }
            next = curr;
        }

        return curr[1][2];
    }
};
