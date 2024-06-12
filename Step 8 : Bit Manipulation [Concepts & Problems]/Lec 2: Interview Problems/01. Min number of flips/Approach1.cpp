class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;

        for(int i=0;i<32;i++)
        {
            int a = start & (1<<i);
            int b = goal & (1<<i);

            if(a!=b)    cnt++;
        }

        return cnt;
    }
};
