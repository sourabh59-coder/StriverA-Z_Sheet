//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int fun(int n)
    {
        int cnt = -1;
        for(int i=0;i<32;i++)
        {
            if(n & (1<<i))
            {
                cnt = i;
            }
        }
        return cnt;
    }
    int countSetBits(int n)
    {
        // Your logic here
        if(n==0)    return 0;
        
        int x = fun(n);
        int xp = x * (1<<(x-1));
        int msb = n - (1 << (x)) + 1;
        
        int rest = n - (1<<x);
        
        return xp + msb + countSetBits(rest);
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends
