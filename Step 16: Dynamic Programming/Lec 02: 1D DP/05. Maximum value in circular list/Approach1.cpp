class Solution {
public:
    int rob_I(vector<int>& v) {
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
    int rob(vector<int>& v) {
        int n = v.size();
        vector<int> v1,v2;
        if(n==1)    return v.back();
        for(int i=0;i<n;i++)
        {
            if(i!=0)    v1.push_back(v[i]);

            if(i!=n-1)   v2.push_back(v[i]);
        }

        // for(int i=0;i<v1.size();i++)    cout<<v1[i]<<" "<<v2[i]<<" ";
        // cout<<endl;

        return max(rob_I(v1),rob_I(v2));
    }
};
