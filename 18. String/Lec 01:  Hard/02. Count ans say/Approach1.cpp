class Solution {
public:
    string countAndSay(int n) {
        if(n==1)    return "1";
        if(n==2)    return "11";

        string s = "11";

        for(int i=3;i<=n;i++)
        {
            int si = s.length();
            string t;
            int cnt = 1;
            char prev = 'a';
            for(int j=0;j<si;j++)
            {
                if(prev!=s[j])
                {
                    if(prev!='a')
                    {
                        t += to_string(cnt);
                        t += prev;
                    }
                    prev = s[j];
                    cnt = 1;
                }
                else    cnt++;
            }
            if(prev==s[si-1])
            {
                t += to_string(cnt);
                t += prev;
            }

            s = t;
        }

        return s;
    }
};
