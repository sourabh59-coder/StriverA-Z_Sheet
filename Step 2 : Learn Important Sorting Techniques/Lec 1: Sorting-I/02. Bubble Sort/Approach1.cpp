void BubbleSort(vector<int> &v,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j],v[j+1]);
            }
        }
    }
}
