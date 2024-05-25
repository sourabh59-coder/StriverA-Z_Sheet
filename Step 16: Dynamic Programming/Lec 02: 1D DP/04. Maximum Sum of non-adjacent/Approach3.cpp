class Solution {
public:
    int rob(vector<int>& v) {
        int n = v.size();
        // vector<int> dp(n+2,0);
        int curr(0),next(0),nextnext(0);
        // return fun(v,0,n,dp);

        for(int i=n-1;i>=0;i--)
        {
            int notTake = 0 + next;

            int Take = v[i] + nextnext;

            curr = max(Take,notTake);

            nextnext = next;
            next = curr;
        }

        return curr;
    }
};
