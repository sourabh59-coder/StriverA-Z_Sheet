#include <bits/stdc++.h>
#define int long long
using namespace std;

string PrefixToPostfix(string s)
{
    stack<string> st;

    for(int i=s.length()-1;i>=0;i--)
    {
        string src;
        src += s[i];

        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            st.push(src);
        }
        
        else
        {
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string s1 = op1 + op2 + src;
            st.push(s1);
        }
    }

    return st.top();
}

signed main()
{
    string s;
    cin>>s;

    cout<<PrefixToPostfix(s)<<endl;

    return 0;
}
