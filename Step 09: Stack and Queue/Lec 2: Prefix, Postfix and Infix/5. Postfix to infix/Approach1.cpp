#include <bits/stdc++.h>
#define int long long
using namespace std;

string PostfixToInfix(string s)
{
    stack<string> st;
    string ans;

    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];
        string src;
        src += s[i];
        
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            st.push(src);
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string s1 = "(" + op2 + src + op1 + ")";
            st.push(s1);
        }
    }

    ans = st.top();

    return ans;
}

signed main()
{
    string s;
    cin>>s;

    cout<<PostfixToInfix(s)<<endl;

    return 0;
}
