#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  int n;
  cin>>n;

  vector<int> v(n);
  for(int i=0;i<n;i++)  cin>>v[i];

  int k;
  cin>>k;

  cout<<lower_bound(v.begin(),v.end(),k) - v.begin()<<endl;

  return 0;
}
