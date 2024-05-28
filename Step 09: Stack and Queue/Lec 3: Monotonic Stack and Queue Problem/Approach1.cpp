class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
        unordered_map<int,int> mp;
        stack<int> st;

        for(int i=v2.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                mp[v2[i]] = -1;
                st.push(v2[i]);
            }
            else
            {
                if(st.top() > v2[i])
                {
                    mp[v2[i]] = st.top();
                    st.push(v2[i]);
                }
                else
                {
                    while(!st.empty() && st.top() < v2[i])
                    {
                        st.pop();
                    }

                    if(st.empty())  mp[v2[i]] = -1;
                    else            mp[v2[i]] = st.top();

                    st.push(v2[i]);
                }
            }
        }

        vector<int> ans;

        for(int i=0;i<v1.size();i++)
        {
            ans.push_back(mp[v1[i]]);
        }

        return ans;
    }
};
