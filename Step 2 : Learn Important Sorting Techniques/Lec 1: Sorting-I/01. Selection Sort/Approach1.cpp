void SelectionSort(vector<int> &v,int n)
{
    for(int i=0;i<n;i++)
    {
        int min = i;

        for(int j=i+1;j<n;j++)
        {
            if(v[min] > v[j])
            {
                min = j;
            }
        }

        if(min!=i)  swap(v[min],v[i]);
    }
}
