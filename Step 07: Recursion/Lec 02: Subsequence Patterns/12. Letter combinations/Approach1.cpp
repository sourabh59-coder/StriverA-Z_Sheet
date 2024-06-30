class Solution {
public:
    void fun(string &digits,vector<string> &ans, unordered_map<int,vector<char>> &mp,int ind,string temp)
    {
        if(ind>=digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<mp[digits[ind]-'0'].size();i++)
        {
            temp.push_back(mp[digits[ind]-'0'][i]);
            fun(digits,ans,mp,ind+1,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>> mp;
        mp[2] = {'a','b','c'} ;
        mp[3] = {'d','e','f'};
        mp[4] = {'g','h','i'};
        mp[5] = {'j','k','l'};
        mp[6] = {'m','n','o'};
        mp[7] = {'p','q','r','s'};
        mp[8] = {'t','u','v'};
        mp[9] = {'w','x','y','z'};
        vector<string> ans;
        if(digits.size()==0)
        {
            return ans;
        }
        fun(digits,ans,mp,0,"");
        return ans;
    }
};
