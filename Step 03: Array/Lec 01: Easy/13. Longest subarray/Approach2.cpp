int longestSubarrayWithSumK(vector<int> v, long long k) {
    // Write your code here
    long long sum = 0;
    unordered_map<long long,int> mp;
    mp[sum] = 0;
    int ans = -1;
    for(int i=0;i<v.size();i++)
    {
        sum += v[i];
        long long val = sum-k;
        if(mp.count(val)!=0)
        {
            ans = max(ans,i+1 - mp[val]);
        }
        if(mp.count(sum)==0)
        {
            mp[sum] = i+1;
        }
    }
    return ans;
}
