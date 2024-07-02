#include <bits/stdc++.h>


int minCost(int v[], int n)
{
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	priority_queue<int, vector<int>, greater<int>> qe;
	for(int i=0;i<n;i++)
	{
		qe.push(v[i]);
	}
	int ans = 0;
	while(qe.size()>1)
	{
		int a = qe.top();
		qe.pop();

		int b = qe.top();
		qe.pop();

		int val = a+b;
		ans += val;
		qe.push(val);
	}
	return ans;
}
