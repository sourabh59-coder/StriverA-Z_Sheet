class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int buy)
    {
        if(ind>=n)  return 0;

        if(buy)     return max((0+fun(v,ind+1,n,buy)),(-v[ind]+fun(v,ind+1,n,1-buy)));

        else        return max((0+fun(v,ind+1,n,buy)),(+v[ind]+fun(v,ind+2,n,1-buy)));
    }
    int maxProfit(vector<int>& v) {
        int n = v.size();
        return fun(v,0,n,1);
    }
};
