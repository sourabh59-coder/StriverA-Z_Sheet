class Solution {
public:
    int FindInd(vector<int> &v,int l,int r,int k)
    {
        int temp = -1;

        while(l<=r)
        {
            int mid = (r-l)/2 + l;

            if(v[mid]>=k)   r = mid-1;
            else
            {
                temp = mid;
                l = mid+1;
            }
        }

        return temp;
    }
    int findKthPositive(vector<int>& v, int k) {
        int n = v.size();
        
        vector<int> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back(v[i]-1-i);
            cout<<vec[i]<<" ";
        }

        int temp = FindInd(vec,0,n-1,k);

        cout<<temp<<endl;

        int to_be_covered = k;
        int curr = 0;
        if(temp!=-1) 
        {
            to_be_covered = k-vec[temp];
            curr = v[temp];
        }   

        return (curr+to_be_covered);
    }
};
