vector<int> Solution::prevSmaller(vector<int> &v) {
    stack<int> st;
    vector<int> ans;
    int n = v.size();
    
    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            if(st.top() < v[i])
            {
                ans.push_back(st.top());
            }
            else
            {
                while(!st.empty() && st.top() >= v[i])
                {
                    st.pop();
                }
                
                if(st.empty())    ans.push_back(-1);
                else            ans.push_back(st.top());
            }
        }
        
        st.push(v[i]);
    }
    
    return ans;
}
