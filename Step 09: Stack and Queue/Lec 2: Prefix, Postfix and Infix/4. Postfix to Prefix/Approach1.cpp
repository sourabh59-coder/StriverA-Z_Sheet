#include <bits/stdc++.h>
#define int long long
using namespace std;

string PostfixToPrefix(string s)
{
    // string ans;
    stack<string> st;

    int n = s.length();

    for(int i=0;i<n;i++)
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

            string s1 = src + op2 + op1;

            st.push(s1);
        }
    }

    return st.top();
}

signed main()
{
    string s;
    cin>>s;

    cout<<PostfixToPrefix(s)<<endl;

    return 0;
}
