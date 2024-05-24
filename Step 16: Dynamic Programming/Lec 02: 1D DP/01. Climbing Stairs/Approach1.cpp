class Solution {
public:
    int fun(int n,int ind)
    {
        if(n==ind)  return 1;
        if(ind>n)   return 0;

        return (fun(n,ind+1) + fun(n,ind+2));
    }

    int climbStairs(int n) {
        return fun(n,0);
    }
};
