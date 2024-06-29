class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        int n = v.size();
        stack<int> st;

        for(int i=0;i<n;i++)
        {
            if(st.empty())  st.push(v[i]);
            else  
            {
                if(st.top()*v[i] > 0)   st.push(v[i]);
                else
                {
                    if(st.top()<0 && v[i]>0)    st.push(v[i]);
                    else
                    {
                        bool flag = true;
                        while(!st.empty() && st.top()>0 && v[i]<0)
                        {
                            int val = st.top();
                            st.pop();

                            if(val>abs(v[i]))
                            {
                                v[i] = val;
                            }
                            else if(val==abs(v[i]))
                            {
                                flag = false;
                                break;
                            }
                            else    continue;
                        } 
                        if(flag)    st.push(v[i]);
                    }
                }   
            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
