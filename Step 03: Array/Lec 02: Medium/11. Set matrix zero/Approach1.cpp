class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        vector<int> v1(n,0);
        vector<int> v2(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==0)
                {
                    v1[i] = 1;
                    v2[j] = 1;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v1[i]==1 || v2[j]==1)
                {
                    v[i][j] = 0;
                }
            }
        }
    }
};
