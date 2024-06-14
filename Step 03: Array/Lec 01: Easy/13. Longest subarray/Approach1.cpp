long long search(vector<long long> v,int l,int r,long long k)
{
    int temp = -1;

    while(l<=r)
    {
        int mid = (r-l)/2 + l;
        if(v[mid]==k)
        {
            temp = mid;
            r = mid-1;
        }
        else if(v[mid] < k)
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }

    return temp;
}

int longestSubarrayWithSumK(vector<int> v, long long k) {
    // Write your code here
    vector<long long> vec;
    vec.push_back(0);
    int n = v.size();
    for(int i=0;i<n;i++)
    {
        vec.push_back(vec.back() + v[i]);
    }
    
    int ans = -1;
    for(int i=1;i<vec.size();i++)
    {
        int l = 0, r = i-1;
        if(vec[i]>=k)
        {
            long long val = vec[i]-k;
            int ind = search(vec,l,r,val);

            if(ind!=-1)
            {
                ans = max(ans,i-ind);
            }
        }
    }
    return ans;
}
