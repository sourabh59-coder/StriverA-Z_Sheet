int longestSuccessiveElements(vector<int>&v) {
    // Write your code here.
    int n = v.size();
    int ans = 0;
    int len = 0;
    int prev = INT_MIN;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(v[i]==prev)  continue;
        if(v[i]-1==prev)
        {
            len++;
            prev = v[i];
            ans = max(ans,len);
        }
        else
        {
            len = 1;
            prev = v[i];
        }
    }

    return ans;
}
