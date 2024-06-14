int longestSubarrayWithSumK(vector<int> v, long long k) {
    // Write your code here
    int n = v.size();
    int i = 0, j = 0;
    int len = 0;
    long long sum = 0;

    while(j<n)
    {
        sum += v[j];

        while(sum>k)
        {
            sum -= v[i];
            i++;
        }

        if(sum==k)
        {
            len = max(len,j-i+1);
        }

        j++;
    }

    return len;
}
