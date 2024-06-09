class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.length();

        for(int i=n-1;i>=0;i--)
        {
            int val = s[i] - '0';
            if(val%2==0)    s.pop_back();
            else            break;
        }

        return s;
    }
};
