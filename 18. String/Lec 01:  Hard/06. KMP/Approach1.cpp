class Solution {
public:
    vector<int> LPS(string s,int n)
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
        return lps;
    }
    int strStr(string haystack, string needle) {
        int n = needle.size();
        vector<int> lps = LPS(needle,n);
        int first = 0;
        int second = 0;
        while(first<haystack.size() && second<n)
        {
            if(haystack[first]==needle[second])
            {
                first++;
                second++;
            }
            else
            {
                if(second==0)
                {
                    first++;
                }
                else
                {
                    second = lps[second-1];
                }
            }
        }

        if(second==n)   return first-second;
        else    return -1;
    }
};
