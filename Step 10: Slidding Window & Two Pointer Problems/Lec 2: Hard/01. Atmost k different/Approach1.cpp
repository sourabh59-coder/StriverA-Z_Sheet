#include <bits/stdc++.h>
int kDistinctChars(int k, string &s)
{
    unordered_map<char,int> mp;
    int n = s.length();
    int  i = 0, j = 0;
    int ans = 0;
    while(j<n)
    {
        mp[s[j]]++;

        while(mp.size()>k)
        {
            mp[s[i]]--;
            if(mp[s[i]]==0) mp.erase(s[i]);
            i++;
        }

        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}


