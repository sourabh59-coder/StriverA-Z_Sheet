class Solution {
public:
    int maxProfit(int k, vector<int>& v) {
        int n = v.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1,0)));
        vector<vector<int>> curr(2, vector<int> (k+1,0));
        vector<vector<int>> next(2, vector<int> (k+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                for(int l=1;l<=k;l++)
                {
                    if(j==1)  curr[j][l] = max((0+next[j][l]),(-v[i]+next[1-j][l]));

                    else    curr[j][l] = max((0+next[j][l]),(v[i]+next[1-j][l-1]));
                }
            }
            next = curr;
        }

        return curr[1][k];
    }
};
