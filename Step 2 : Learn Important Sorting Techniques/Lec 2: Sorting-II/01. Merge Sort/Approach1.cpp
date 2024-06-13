
void Merge(vector<int> &v,int l,int k,int r)
{
    vector<int> temp;
    int i = l, j = k+1;

    while(i<=k && j<=r)
    {
        if(v[i]>=v[j])
        {
            temp.push_back(v[j]);
            j++;
        }
        else
        {
            temp.push_back(v[i]);
            i++;
        }
    }

    while(i<=k)
    {
        temp.push_back(v[i]);
        i++;
    }

    while(j<=r)
    {
        temp.push_back(v[j]);
        j++;
    }


    // int ind = 0;
    for(int p=l;p<=r;p++)
    {
        v[p] = temp[p-l];
        // ind++;
    }
}

void MergeSort(vector<int> &v,int l,int r)
{
    if(l<r)
    {
        int mid = (r-l)/2 + l;

        MergeSort(v,l,mid);

        MergeSort(v,mid+1,r);

        Merge(v,l,mid,r);
    }
}
