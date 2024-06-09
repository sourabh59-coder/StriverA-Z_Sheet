class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stack<string> st;
        int n = s.length();
        string str = "";

        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
                str += s[i];
            }
            else
            {
                if(str!="")
                {
                    st.push(str);
                    str = "";
                }
            }
        }
        if(str!="")
        {
            st.push(str);
            str = "";
        }

        while(st.size()!=1)
        {
            string node = st.top();
            st.pop();

            ans += node + ' ';
        }
        if(!st.empty())
        {
            string node = st.top();
            st.pop();

            ans += node ;
        }
        return ans;
    }
};
