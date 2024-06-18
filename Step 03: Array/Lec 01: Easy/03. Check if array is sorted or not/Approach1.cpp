class Solution {
public:
    bool check(vector<int>& v) {
        int cnt = 0;
        int ind = 0;
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>v[i+1])
            {
                cnt++;
                ind = i+1;
            } 
        }
        if(cnt==0 || cnt==1)
        {
            for(int i=0;i<v.size()-1;i++)
            {
                int j = (ind+i)%(v.size());
                int k = (ind+i+1)%(v.size());
                if(v[j] > v[k]) return false;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
};
