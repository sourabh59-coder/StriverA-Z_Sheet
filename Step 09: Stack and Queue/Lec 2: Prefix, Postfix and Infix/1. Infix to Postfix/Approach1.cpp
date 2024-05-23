int precedence(char ch)
  {
      if(ch=='^')   return 3;
      else if(ch=='*' || ch=='/')   return 2;
      else if(ch=='+' || ch=='-')   return 1;
      else  return 0;
  }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        string ans = "";
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
             
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))    ans += ch;
            
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
                while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
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
        
        return ans;
    }
