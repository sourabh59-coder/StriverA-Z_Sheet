class Solution {
public:
    bool rotateString(string s, string t) {
        if(s.size()!=t.size())  return false;
        s = s + s;
        int n = t.length();
        for(int i=0;i<n;i++)
        {
            if(s.substr(i,n)==t)    return true;
        }
        return false;
    }
};
