class Solution {
public:
    int LPS(string s,int n)
    {
        vector<int> lps(n,0);
        int pre = 0, suf = 1;

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
        return lps[n-1];
    }
    string shortestPalindrome(string s1) {
        string s = s1;
        string str = s;
        int n = s.length();
        reverse(str.begin(),str.end());
        s.push_back('#');
        for(int i=0;i<n;i++)    s.push_back(str[i]);
        int val = LPS(s,s.length());
        int rem = n-val;
        string rem_str = s1.substr(val,rem);
        reverse(rem_str.begin(),rem_str.end());
        for(int i=0;i<s1.length();i++)  rem_str.push_back(s1[i]);
        return rem_str;
    }
};
