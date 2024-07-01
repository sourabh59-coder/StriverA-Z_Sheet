#include <bits/stdc++.h>
// #define int long long 
using namespace std;

int cnt = 0;


void Merge(vector<int> &v,int low,int mid,int high)
{
    vector<int> temp;
    int l = low, r = mid+1;

    while(l<=mid && r<=high)
    {
        if(v[l]<=v[r])
        {
            temp.push_back(v[l]);
            l++;
        }
        else
        {
            temp.push_back(v[r]);
            r++;
        }
    }

    while(l<=mid)
    {
        temp.push_back(v[l]);
        l++;
    }

    while(r<=high)
    {
        temp.push_back(v[r]);
        r++;
    }

    int k = 0;
    for(int i = low; i <= high ; i++)
    {
        v[i] = temp[k++];
    }
}

void Count(vector<int> &v,int low,int mid,int high)
{
    int right = mid+1;

    for(int i=low;i<=mid;i++)
    {
        while(right<=high && v[i]>(2*v[right]))    right++;
        cnt += (right-(mid+1));
    }
}

void MergeSort(vector<int> &v,int low,int high)
{
    if(high<=low)   return;


    int mid = (low+high)/2;

    MergeSort(v,low,mid);
    MergeSort(v,mid+1,high);
    Count(v,low,mid,high);
    Merge(v,low,mid,high);
}

int team(vector <int> & skill, int n)
{
    // Write your code here.
    MergeSort(skill,0,n-1);
    return cnt;
}
