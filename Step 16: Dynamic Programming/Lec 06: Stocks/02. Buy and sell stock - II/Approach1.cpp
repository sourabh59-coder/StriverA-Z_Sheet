class Solution {
public:
    int fun(vector<int> &v,int ind,int n,bool buy)
    {
        if(ind==n)  return 0;

        if(buy)
        {
            return max( 0+fun(v,ind+1,n,true) , -v[ind]+fun(v,ind+1,n,false));
        }

        else
        {
            return max( 0+fun(v,ind+1,n,false) , v[ind]+fun(v,ind+1,n,true));
        }
    }
    int maxProfit(vector<int>& v) {
        int n = v.size();
        bool buy = true;
        return fun(v,0,n,true,dp);
    }
};
