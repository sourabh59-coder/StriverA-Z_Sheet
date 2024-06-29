class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();

        stack<int> st;
        for(int i=0;i<n;i++)
        {
            int val = s[i]-'0';
            if(st.empty())  st.push(val);
            else
            {
                while(!st.empty() && st.top()>val && k>0)
                {
                    st.pop();
                    k--;
                }
                st.push(val);
            }
        }

        while(k>0 && !st.empty())
        {
            st.pop();
            k--;
        }

        int i = 0;
        string ans = "";
        while(!st.empty())
        {
            string str =  to_string(st.top());
            st.pop();

            ans += str;
        }
        while(ans.size()!=0 && ans[ans.size()-1]=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return (ans.size()==0) ? "0":ans;
    }
};
