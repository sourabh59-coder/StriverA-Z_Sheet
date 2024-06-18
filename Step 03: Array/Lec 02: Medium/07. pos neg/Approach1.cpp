class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)   pos.push_back(nums[i]);
            else            neg.push_back(nums[i]);
        }
        int a=0,b=0;
        int k=0, si = n/2;
        while(si--)
        {
            nums[k++] = pos[a++];
            nums[k++] =  neg[b++];
        }
        return nums;
    }
};
