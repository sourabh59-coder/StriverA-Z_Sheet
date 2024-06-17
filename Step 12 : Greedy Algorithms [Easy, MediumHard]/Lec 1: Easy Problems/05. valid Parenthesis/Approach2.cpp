class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int minv = 0;
        int maxv = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                minv++;
                maxv++;
            }
            else if(s[i]==')')
            {
                minv--;
                maxv--;
            }
            else
            {
                minv--;
                maxv++;
            }
            if(minv<0)  minv = 0;
            if(maxv<0)  return false;
        }
        return (minv==0);
    }
};
