int Solution::solve(vector<int> &v, int k) {
    int n = v.size();
    vector<int> vec;
    vec.push_back(v[0]);
    unordered_map<int,int> mp;
    mp[v[0]]++;
    int ans = 0;
    if(v[0]==k) ans++;
    for(int i=1;i<n;i++)
    {
        int val = vec.back() ^ v[i];
        vec.push_back(val);
        if(val==k)  ans++;
        if(mp.count(val^k)!=0)  ans += mp[val^k];
        mp[val]++;
    }
    return ans;
}
