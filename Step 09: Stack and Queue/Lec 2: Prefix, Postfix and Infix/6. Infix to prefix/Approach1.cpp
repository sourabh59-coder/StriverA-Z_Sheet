#include <bits/stdc++.h>
#define int long long
using namespace std;

int precedence(char ch)
{
    if(ch=='^') return 3;
    if(ch=='*' || ch=='/')  return 2;
    if(ch=='-' || ch=='+')  return 1;
    else    return 0;
}

string InfixToPrefix(string s)
{
    string ans = "";
    stack<char> st;

    reverse(s.begin(),s.end());

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')   s[i] = ')';
        else if(s[i]==')')  s[i] = '(';
    }

    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];

        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            ans += ch;
        }

        else if(ch=='(')    st.push(ch);

        else if(ch==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans += st.top();
                st.pop();
            }

            if(!st.empty()) st.pop();
        }

        else
        {
            while(!st.empty() && precedence(st.top()) >= precedence(ch))
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

signed main()
{
    string s;
    cin>>s;

    cout<<InfixToPrefix(s)<<endl;

    return 0;
}
