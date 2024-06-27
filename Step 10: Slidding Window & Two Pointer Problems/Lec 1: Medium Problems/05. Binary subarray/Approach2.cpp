class Solution {
public:
    int binary_search_lower(vector<int> &v,int left,int right,int key)
    {
        int temp = -1;

        while(left<=right)
        {
            int mid = left + (right-left)/2;

            if(v[mid]==key)
            {
                temp = mid;
                right = mid-1;
            }
            else if(v[mid] < key)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }

        return temp;
    }

    int binary_search_upper(vector<int> &v,int left,int right,int key)
    {
        int temp = -1;

        while(left<=right)
        {
            int mid = left + (right-left)/2;

            if(v[mid]==key)
            {
                temp = mid;
                left = mid+1;
            }
            else if(v[mid] < key)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }

        return temp;
    }
    
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> v;
        int ans = 0;
        
        v.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            int val = v.back()+nums[i];
            v.push_back(val);
        }
        
        int n = v.size();
        for(int i=0;i<n;i++)    cout<<v[i]<<" ";
        cout<<endl;
        int ind = binary_search_lower(v,0,n-1,goal);
        if(ind==-1) return 0;
        if(ind==0)  ind++;
        
        for(int i=ind;i<n;i++)
        {
            int l = 0;
            int r = i-1;
            int key = v[i]-goal;
            
            int ind_l = binary_search_lower(v,l,r,key);
            int ind_r = binary_search_upper(v,l,r,key);
            if(ind_l!=-1 && ind_r!=-1)    ans += (ind_r-ind_l+1);
        }
        
        
        return ans;
    }
};
