class Solution {
public:
    bool lemonadeChange(vector<int>& v) {
        int a(0),b(0);
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]==5)
            {
                a++;
            }
            else if(v[i]==10)
            {
                if(a>0)
                {
                    a--;
                    b++;
                }
                else    return false;
            }
            else
            {
                if(a>=1 && b>=1)
                {
                    a--;
                    b--;
                }
                else if(a>=3)
                {
                    a -= 3;
                }
                else    return false;
            }
        }
        return true;
    }
};
