class Solution {
public:
    bool isPallindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            {
                return false;
            }
        }
        return true;
    }
    void fun(string s,int ind,int n,vector<vector<string>> &ans,vector<string> &temp)
    {
        if(ind==n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<n;i++)
        {
            if(isPallindrome(s,ind,i))
            {
                string pall = s.substr(ind,i-ind+1);
                temp.push_back(pall);
                fun(s,i+1,n,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.length();
        vector<string> temp;
        fun(s,0,n,ans,temp);
        return ans;
    }
};
