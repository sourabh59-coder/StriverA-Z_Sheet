#include <bits/stdc++.h>
#define int long long
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    unordered_set<char> st;
    int left = 0;
    int ans = 0;
    
    for(int i=0;i<n;i++)
    {
        if(st.count(s[i])==0)
        {
            st.insert(s[i]);
            ans = max(ans,i-left+1);
        }
        else
        {
            while(st.count(s[i]))
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
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
