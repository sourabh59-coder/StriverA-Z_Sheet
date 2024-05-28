class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int ans = 0;
        int n = v.size();
        vector<int> sr;
        vector<int> sl;
        stack<pair<int,int>> st;

        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                sl.push_back(-1);
            }
            else
            {
                if(st.top().first < v[i])
                {
                    sl.push_back(st.top().second);
                }
                else
                {
                    while(!st.empty() && st.top().first >= v[i])
                    {
                        st.pop();
                    }

                    if(st.empty())  sl.push_back(-1);
                    else            sl.push_back(st.top().second);
                }
            }

            st.push({v[i],i});
        }

        while(!st.empty())  st.pop();

        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                sr.push_back(n);
            }
            else
            {
                if(st.top().first < v[i])
                {
                    sr.push_back(st.top().second);
                }
                else
                {
                    while(!st.empty() && st.top().first >= v[i])
                    {
                        st.pop();
                    }

                    if(st.empty())      sr.push_back(n);
                    else                sr.push_back(st.top().second);
                }
            }

            st.push({v[i],i});
        }

        reverse(sr.begin(),sr.end());

        for(int i=0;i<n;i++)
        {
            int val = (sr[i]-sl[i]-1);
            ans = max(ans,(val*v[i]));
        }

        return ans;
    }
};
