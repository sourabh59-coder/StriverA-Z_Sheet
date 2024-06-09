class Solution {
public:
    bool rotateString(string s, string t) {
        int n = s.length();

        if(n!=t.length())   return false;

        bool ans = false;

        for(int i=0;i<n;i++)
        {
            bool flag = true;
            for(int j=0;j<n;j++)
            {
                int k = (j+i) % n;
                if(s[j]!=t[k])  flag = false;
            }
            if(flag)    ans = true;
        }

        return ans;
    }
};
