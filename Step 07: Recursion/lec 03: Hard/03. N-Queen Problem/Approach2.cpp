class Solution {
public:
    void fun(int ind,int n,vector<string> &ds,vector<vector<string>> &ans,vector<int> &hash1,vector<int> &hash2,vector<int> &hash3)
    {
        if(ind==n)
        {
            ans.push_back(ds);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(hash1[row]==0 && hash2[row+ind]==0 && hash3[n-1 + ind-row]==0)
            {
                ds[row][ind] = 'Q';
                hash1[row] = 1;
                hash2[row+ind] = 1;
                hash3[n-1 + ind-row] = 1;
                fun(ind+1,n,ds,ans,hash1,hash2,hash3);
                hash1[row] = 0;
                hash2[row+ind] = 0;
                hash3[n-1 + ind-row] = 0;
                ds[row][ind] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds;
        string s(n,'.');
        for(int i=0;i<n;i++)    ds.push_back(s);
        vector<int> hash1(n,0);
        vector<int> hash2(2*n-1,0);
        vector<int> hash3(2*n-1,0);
        fun(0,n,ds,ans,hash1,hash2,hash3);
        return ans;
    }
};
