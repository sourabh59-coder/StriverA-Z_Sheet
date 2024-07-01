#include <bits/stdc++.h>

std::vector<int> findMissingRepeatingNumbers(std::vector<int> v) {
    int n = v.size();
    int xor_all = 0;
    for(int i=0;i<n;i++)
    {
        xor_all ^= v[i];
        xor_all ^= (i+1);
    }    

    int bit_no = 0;
    for(int i=0;i<=32;i++)
    {
        if(xor_all & 1<<i)  bit_no = i;
    }

    int a = 0;
    int b = 0;

    for(int i=0;i<n;i++)
    {
        if(v[i] & (1<<bit_no))  a^=v[i];
        else                    b^=v[i];

        if((i+1) & (1<<bit_no)) a^=(i+1);
        else                b^=(i+1);
    }
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        if(v[i]==a) flag = true;
    }

    vector<int> ans;
    if(!flag)
    {
        ans.push_back(b);
        ans.push_back(a);
    }
    else
    {
        ans.push_back(a);
        ans.push_back(b);
    }
    return ans;
}
