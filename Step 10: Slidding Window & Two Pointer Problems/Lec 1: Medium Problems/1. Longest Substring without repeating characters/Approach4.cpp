#include <bits/stdc++.h>
#define int long long
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    vector<int> ind(128,-1);
    int left = 0;
    int ans = 0;
    
    for(int i=0;i<n;i++)
    {
        if(ind[s[i]]>=left)
        {
            left = ind[s[i]]+1;
        }
        ind[s[i]] = i;
        ans = max(ans,i-left+1);
    }
    
    return ans;
}

signed main()
{
    string s;
    cin>>s;
    
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}
