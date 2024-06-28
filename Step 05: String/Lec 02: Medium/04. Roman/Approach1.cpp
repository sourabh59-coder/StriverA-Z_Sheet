class Solution {
public:
    int romanToInt(string s) {
        int count = 0,arr[15];
        if(s.length()==0)
        {
            count = -1;
        }
        else
        {
            for(int i=s.length()-1;i>=0;i--)
            {
                switch(s[i])
                {
                    case 'I':
                        arr[i] = 1;
                        break;
                    case 'V':
                        arr[i] = 5;
                        break;
                    case 'X':
                        arr[i] = 10;
                        break;
                    case 'L':
                        arr[i] = 50;
                        break; 
                    case 'C':
                        arr[i] = 100;
                        break;
                    case 'D':
                        arr[i] = 500;
                        break; 
                    case 'M':
                        arr[i] = 1000;
                        break;
                }
            }
            for(int i=0;i<s.length()-1;i++)
            {
                if(arr[i]<arr[i+1])
                {
                    count -= arr[i];
                }
                else
                {
                    count += arr[i];
                }
            }
            count += arr[s.length()-1];
        }
        return count;
    }
};
