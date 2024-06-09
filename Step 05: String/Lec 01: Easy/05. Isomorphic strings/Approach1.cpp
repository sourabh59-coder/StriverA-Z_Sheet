class Solution {
public:
    bool checkFun(string s,string t)
    {
        vector<int> check(130,-1);
        for(int i=0;i<s.length();i++)
        {
            int key = s[i];
            int val = t[i];
            if(check[key]==-1)  check[key] = val;
            else
            {
                if(check[key]!=val) return false;
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        
        if(s.length()!=t.length())  return false;
        // bool ans = true;
        
        return checkFun(s,t) && checkFun(t,s);
    }
};
