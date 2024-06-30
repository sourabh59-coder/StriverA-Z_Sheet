//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void Insert(int val,stack<int> &st)
{
    if(st.size()==0 || st.top()<=val)
    {
        st.push(val);
        return;
    }
    
    int temp = st.top();
    st.pop();
    Insert(val,st);
    st.push(temp);
}

void SortedStack :: sort()
{
   //Your code here
   if(s.size()==0||s.size()==1)   return;
   
   int val = s.top();
   s.pop();
   
   sort();
   
   Insert(val,s);
}
