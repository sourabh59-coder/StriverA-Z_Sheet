vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int> v{1000,500,100,50,20,10,5,2,1};
    vector<int> ans;

    for(int i=0;i<v.size() && n>0;i++)
    {
        int val = n/v[i];
        n = n % v[i];
        while(val--)
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}
