#include <bits/stdc++.h>
#define int long long
using namespace std;

void fun(int k,int ind,int prev,string &s,vector<string> &ans)
{
    if(ind==k)
    {
        ans.push_back(s);
        return;
    }    
    
    // Take
    if(prev==-1 || s[prev]=='0')
    {
        s.push_back('1');
        fun(k,ind+1,ind,s,ans);
        s.pop_back();
    }
    
    // notTake
    s.push_back('0');
    fun(k,ind+1,ind,s,ans);
    s.pop_back();
}

signed main()
{
    int k;
    cin>>k;
    
    vector<string> ans;
    string s;
    
    fun(k,0,-1,s,ans);
    
    for(int i=0;i<ans.size();i++)   cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
