#include <bits/stdc++.h>
#define int long long
using namespace std;

string PrefixToInfix(string s)
{
    stack<string> st;
    string ans;

    for(int i=s.length()-1;i>=0;i--)
    {
        string src;
        src += s[i];

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
        {
            st.push(src);
        }

        else
        {
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string s1 = "(" + op1 + src + op2 + ")";
            st.push(s1);
        }
    }

    ans = st.top();

    // reverse(ans.begin(),ans.end());

    return ans;
}

signed main()
{
    string s;
    cin>>s;
    
    cout<<PrefixToInfix(s)<<endl;

    return 0;
}
