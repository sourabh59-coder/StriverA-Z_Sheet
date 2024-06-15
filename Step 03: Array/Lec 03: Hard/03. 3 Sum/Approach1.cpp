class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();
        unordered_set<int> st;
        sort(v.begin(),v.end());
        st.insert(v[0]);
        set<vector<int>> ans;
        for(int i=1;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int val = v[i]+v[j];
                if(st.count((-1 * val))!=0)
                {
                    ans.insert({-1*val, v[i],v[j]});
                }
            }
            st.insert(v[i]);
        }
        vector<vector<int>> a;
        for(auto it=ans.begin();it!=ans.end();it++)
        {
            a.push_back(*it);
        }
        return a;
    }
};
