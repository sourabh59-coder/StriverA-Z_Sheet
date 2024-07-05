class Solution {
public:
    string LPS(string s,int n)
    {
        vector<int> lps(n,0);
        int pre = 0;
        int suf = 1;
        while(suf<n)
        {
            if(s[pre]==s[suf])
            {
                lps[suf] = pre+1;
                suf++;
                pre++;
            }
            else
            {
                if(pre==0)
                {
                    suf++;
                }
                else
                {
                    pre = lps[pre-1];
                }
            }
        }
        string str = s.substr(0,lps[n-1]);
        return str;
    }
    string longestPrefix(string s) {
        return LPS(s,s.length());
    }
};
