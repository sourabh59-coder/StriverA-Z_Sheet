class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans = "";
        int n =  s.size();
        int si = 200;
        for(int i=0;i<n;i++)    si = min(si,(int)s[i].size());

        for(int i=0;i<si;i++)
        {
            char ch = s[0][i];
            bool flag = true;
            for(int j=1;j<n;j++)
            {
                if(ch!=s[j][i])     flag = false;
            }
            if(flag)    ans += ch;
            else        break;
        }

        return ans;
    }
};
