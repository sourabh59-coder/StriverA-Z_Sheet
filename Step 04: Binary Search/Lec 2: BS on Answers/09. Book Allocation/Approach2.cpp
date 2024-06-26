#include <bits/stdc++.h>

bool isPossible(vector<int> &v,int n,int m,int thres)
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

    return (cnt<=m);
}

int findPages(vector<int>& v, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int l = INT_MIN;
    int r = 0;

    for(int i=0;i<n;i++)
    {
        l = max(l,v[i]);
        r += v[i];
    }

    int temp = -1;

    while(l<=r)
    {
        int mid = (r-l)/2 + l;

        if(isPossible(v,n,m,mid))
        {
            temp = mid;
            r = mid-1;
        }
        else    l = mid+1;
    }

    return temp;

    // for(int i=l;i<=r;i++)
    // {
    //     if(isPossible(v,n,m,i))
    //     {
    //         return i;
    //     }
    // }

    // return -1;
}
