class Solution {
public:
    int LongestCommon(string s1,string s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<int> curr(m+1, 0);
        vector<int> prev(m+1, 0);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])     curr[j] = (1 + prev[j-1]);

                else                 curr[j] = max(prev[j] , curr[j-1]);
            }
            prev = curr;
        }

        return curr[m];
    }
    int minInsertions(string s) {
        string str = s;
        reverse(str.begin(),str.end());
        int val = LongestCommon(s,str);

        return s.length() - val;
    }
};
