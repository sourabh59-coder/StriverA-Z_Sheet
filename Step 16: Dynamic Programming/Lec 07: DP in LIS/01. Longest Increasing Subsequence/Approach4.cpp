class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> arr(n,1);
        vector<int> hash(n);

        int maxi = 0;
        int maxv = 1;

        vector<int> ans;

        for(int i=0;i<n;i++)    hash[i] = i;

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
                        maxv = max(maxv,arr[i]);
                        maxi = i;
                    }
                }
            }
        }

        while(maxi!=hash[maxi])
        {
            ans.push_back(v[maxi]);
            maxi = hash[maxi];
        }

        ans.push_back(v[maxi]);


        reverse(ans.begin(),ans.end());

        for(int i=0;i<ans.size();i++)   cout<<ans[i]<<" ";
        cout<<endl;

        return maxv;
    }
};
