class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        int n = v.size();

        for(int i=0;i<pow(2,n);i++)
        {
            vector<int> vec;
            for(int j=0;j<n;j++)
            {
                if((1<<j) & i)
                {
                    vec.push_back(v[j]);
                }
            }
            ans.push_back(vec);
        }

        return ans;
    }
};
