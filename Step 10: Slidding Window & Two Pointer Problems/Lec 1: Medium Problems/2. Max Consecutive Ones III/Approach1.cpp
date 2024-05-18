#include <bits/stdc++.h>
#define int long long
using namespace std;

int longestOnes(vector<int> &v,int k)
{
    int n = v.size();
    int left = 0;
    int ans = 0;
    
    for(int right=0;right<n;right++)
    {
        if(!v[right])
        {
            if(k>0)
            {
                k--;
            }
            else
            {
                while(k<=0)
                {
                    if(!v[left])    k++;
                    left++;
                }
                k--;
            }
            ans = max(ans,right-left+1);
        }
        else
        {
            ans = max(ans,right-left+1);
        }
    }
    
    return ans;
}

signed main()
{
    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];
    
    int k;
    cin>>k;
    
    cout<<longestOnes(v,k)<<endl;
    
    return 0;
}
