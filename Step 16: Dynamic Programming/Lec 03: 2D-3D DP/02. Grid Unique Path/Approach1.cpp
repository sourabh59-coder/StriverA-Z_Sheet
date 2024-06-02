class Solution {
public:
    int fun(int m,int n)
    {
        if(m==0 && n==0)    return 1;

        if(m<0 || n<0)  return 0;

        int left = fun(m-1,n);
        int right = fun(m,n-1);

        return (left + right);
    }
    int uniquePaths(int m, int n) {
        return fun(m-1,n-1);
    }
};
