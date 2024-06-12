class Solution {
public:
    void fun(int n,int i,int j,int ind,int k,string &s,vector<string> &ans)
    {
        if(ind==k)
        {
            ans.push_back(s);
            return;
        }

        // '(' parenthesis: -
        if(i<n)
        {
            s.push_back('(');
            fun(n,i+1,j,ind+1,k,s,ans);
            s.pop_back();
        }

        // ')' parenthesis: -
        if(j<i)
        {
            s.push_back(')');
            fun(n,i,j+1,ind+1,k,s,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        fun(n,0,0,0,n*2,s,ans);
        return ans;
    }
};
