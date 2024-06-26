class Solution {
public:
    bool canJump(vector<int>& v) {
        int ind = 0;
        for(int i=0;i<v.size();i++)
        {
            if(ind>=i)
            {
                ind = max(ind,v[i]+i);
            }
        }
        return (ind>=v.size()-1);
    }
};
