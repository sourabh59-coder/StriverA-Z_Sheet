class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            if(ans.empty())
            {
                ans.push_back(v[i]);
            }
            else
            {
                int a = ans.back()[0];
                int b = ans.back()[1];
                ans.pop_back();

                int x = v[i][0];
                int y = v[i][1];

                if(b>=x)
                {
                    b = max(b,y);
                    ans.push_back({a,b});
                }
                else
                {
                    ans.push_back({a,b});
                    ans.push_back({x,y});
                }
            }
        }

        return ans;
    }
};
