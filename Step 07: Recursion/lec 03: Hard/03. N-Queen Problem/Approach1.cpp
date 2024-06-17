class Solution {
public:
    bool isSafe(int n,int ind,int row,vector<string> &ds)
    {
        int c = ind, r = row;
        
        while(ind>=0)
        {
            if(ds[row][ind]=='Q')   return false;
            ind--;
        }

        ind = c, row = r;

        while(ind>=0 && row>=0)
        {
            if(ds[row][ind]=='Q')   return false;
            ind--;
            row--;
        }

        ind = c, row = r;

        while(ind>=0 && row<n)
        {
            if(ds[row][ind]=='Q')   return false;
            ind--;
            row++;
        }

        return true;
    }
    void fun(int ind,int n, vector<string> &ds,vector<vector<string>> &ans)
    {
        if(ind==n)
        {
            ans.push_back(ds);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(isSafe(n,ind,row,ds))
            {
                ds[row][ind] = 'Q';
                fun(ind+1,n,ds,ans);
                ds[row][ind] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds;
        string s(n,'.');
        for(int i=0;i<n;i++)    ds.push_back(s);
        fun(0,n,ds,ans);
        return ans;
    }
};
