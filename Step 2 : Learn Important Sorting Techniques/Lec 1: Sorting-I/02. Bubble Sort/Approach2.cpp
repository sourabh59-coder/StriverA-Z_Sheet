void OptimizedBubbleSort(vector<int> &v,int n)
{
    for(int i=0;i<n;i++)
    {
        bool flag = true;
        for(int j=0;j<n-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                flag = false;
                swap(v[j],v[j+1]);
            }
        }
        if(flag)    break;
    }
}
