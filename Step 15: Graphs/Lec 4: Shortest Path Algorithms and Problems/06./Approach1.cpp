class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> check(n, vector<int> (m , 1e9));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> qe;
        qe.push({0,{0,0}});
        check[0][0] = 0;

        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();
            int val = it.first;
            int x = it.second.first;
            int y = it.second.second;

            // if(x==n-1 && y==m-1)    return val;

            for(auto moment: moments)
            {
                int child_x = x + moment.first;
                int child_y = y + moment.second;

                if(child_x>=0 && child_y>=0 && child_x<n && child_y<m)
                {
                    int value = max(abs(v[x][y] - v[child_x][child_y]) , check[x][y]);
                    if(check[child_x][child_y] > value)
                    {
                        check[child_x][child_y] = value;
                        qe.push({value,{child_x,child_y}});
                    }
                }
            }
        }

        return check[n-1][m-1];
    }
};
