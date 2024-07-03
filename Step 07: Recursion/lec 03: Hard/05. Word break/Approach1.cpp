// TLE Code as this is not suitable for such complexity but is a similar type of pallindromic division type questions => submitting just to save


class Solution {
public:
    void fun(string s,int ind,int n,vector<vector<string>> &ans,vector<string> &temp,unordered_set<string>& dict)
    {
        if(ind==n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<n;i++)
        {
            string pall = s.substr(ind,i-ind+1);
            if(dict.count(pall))
            {
                temp.push_back(pall);
                fun(s,i+1,n,ans,temp,dict);
                temp.pop_back();
            }
        }
    }
    bool wordBreak(string s, vector<string>& vec) {
        vector<vector<string>> ans;
        int n = s.length();
        vector<string> temp;
        unordered_set<string> dict;
        for(int i=0;i<vec.size();i++)
        {
            dict.insert(vec[i]);
        }
        fun(s,0,n,ans,temp,dict);
        return (ans.size()>0);
    }
};
