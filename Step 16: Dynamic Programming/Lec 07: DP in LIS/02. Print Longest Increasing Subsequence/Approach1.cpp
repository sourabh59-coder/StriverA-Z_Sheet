vector<int> longestIncreasingSubsequence(int n, vector<int>& v) {
        vector<int> hash(n);
        for(int i=0;i<n;i++)    hash[i] = i;
        vector<int> arr(n,1);
        int maxv = 1;
        int maxi = 0;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[j] < v[i])
                {
                    if(arr[j] + 1 > arr[i])
                    {
                        arr[i] = arr[j] + 1;
                        hash[i] = j;
                        if(arr[i] > maxv)
                        {
                            maxv = arr[i];
                            maxi = i;
                        }
                    }
                }
            }
        }
        
        vector<int> ans;
        
        while(maxi != hash[maxi])
        {
            ans.push_back(v[maxi]);
            maxi = hash[maxi];
        }
        
        ans.push_back(v[maxi]);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
