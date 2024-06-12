//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int n)
    {
        // Write Your Code here
        int val = 0;
        bool flag = true;
        for(int i=0;i<32;i++)
        {
            int key = (1<<i);
            if((key & n))
            {
                val |= key;
            }
            else
            {
                if(flag)
                {
                    val |= key;
                    flag = false;
                }
            }
        }
        return val;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
