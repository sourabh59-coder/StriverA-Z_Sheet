#include <bits/stdc++.h>
#define int long long
using namespace std;
//Using the string directly and not using any type of data structure 
int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    int left = 0;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=left;j--)
        {
            if(s[i]==s[j])
            {
                left = j+1;
                break;
            }
        }
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
