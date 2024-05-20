#include <bits/stdc++.h>
#define int long long
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    unordered_map<char,int> mp;
    int left = 0;
    int ans = 0;
    
    for(int i=0;i<n;i++)
    {
        if(mp.count(s[i])==0 || mp[s[i]]<left)
        {
            mp[s[i]] = i;
            ans = max(ans,i-left+1);
        }
        else
        {
            left = mp[s[i]]+1;
            mp[s[i]] = i;
        }
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
