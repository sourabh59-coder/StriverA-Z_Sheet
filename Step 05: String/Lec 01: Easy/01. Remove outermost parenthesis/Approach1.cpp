class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        int n = s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(st.empty())
                {
                    st.push(s[i]);
                }
                else
                {
                    ans.push_back(s[i]);
                    st.push(s[i]);
                }
            }
            else
            {
                if(st.size()==1)    st.pop();
                else
                {
                    ans.push_back(s[i]);
                    st.pop();
                }
            }
        }

        return ans;
    }
};
