#include <bits/stdc++.h>

bool isPossible(vector<int> &v,int n,int k,int thres)
{
    int cnt = 1;
    int val = v[0];

    for(int i=1;i<n;i++)
    {
        if(val+v[i]>thres)
        {
            cnt++;
            val = v[i];
        }
        else    val += v[i];
    }

    return (cnt<=k);
}

int findLargestMinDistance(vector<int> &v, int k)
{
    //    Write your code here.
    int n = v.size();
    
    int l = INT_MIN;
    int r = 0;

    for(int i=0;i<n;i++)
    {
        l = max(l,v[i]);
        r += v[i];
    }

    // for(int i=l;i<=r;i++)
    // {
    //     if(isPossible(v,n,k,i))
    //     {
    //         return i;
    //     }
    // }

    // return -1;

    int temp = -1;

    while(l<=r)
    {
        int mid = (r-l)/2 + l;

        if(isPossible(v,n,k,mid))
        {
            temp = mid;
            r = mid-1;
        }
        else    l = mid+1;
    }

    return temp;
}
