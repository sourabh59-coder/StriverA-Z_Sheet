class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int k,int buy)
    {
        if(ind==n)  return 0;
        
        if(k==0)    return 0;

        if(buy==1)  return max((0+fun(v,ind+1,n,k,buy)),(-v[ind]+fun(v,ind+1,n,k,1-buy)));

        else    return max((0+fun(v,ind+1,n,k,buy)),(v[ind]+fun(v,ind+1,n,k-1,1-buy)));
    }
    int maxProfit(int k, vector<int>& v) {
        int n = v.size();
        return fun(v,0,n,k,1);
    }
};
