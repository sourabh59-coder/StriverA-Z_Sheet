class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> check(27,0);
        if(s.length()!=t.length())  return false;
        for(int i=0;i<s.length();i++)
        {
            int a = s[i]-'a';
            int b = t[i]-'a';
            check[a]++;
            check[b]--;
        }
        for(int i=0;i<27;i++)   if(check[i]!=0) return false;
        return true;
    }
};
