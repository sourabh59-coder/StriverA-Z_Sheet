class Solution {
public:
    int fun(string s,string t,int n,int m)
    {
        if(m<0)    return 1;
        if(n<0 && m>=0) return 0;

        if(s[n]==t[m])  return (fun(s,t,n-1,m-1) + fun(s,t,n-1,m));

        else            return (fun(s,t,n-1,m));
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        return fun(s,t,n-1,m-1);
    }
};
