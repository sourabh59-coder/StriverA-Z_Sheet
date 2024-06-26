#include <bits/stdc++.h>
#define int long long
using namespace std;

class MinHeap{
  public:
    int *harr;
    int capacity;
    int heap_size;
    
    MinHeap(int c)
    {
        capacity = c;
        heap_size = 0;
        harr = new int[c];
    }
    
    int parent(int i)
    {
        return (i-1)/2;
    }
    
    int left(int i)
    {
        return (2*i+1);
    }
    
    int right(int i)
    {
        return (2*i+2);
    }
    
    int getMin()
    {
        if(heap_size==0)    return -1;
        else                return harr[0];
    }
    
    void InsertKey(int k)
    {
        if(heap_size==capacity)
        {
            cout<<"Heap already full"<<endl;
            return;
        }
        
        heap_size++;
        harr[heap_size-1] = k;
        int i = heap_size - 1;
        
        while(i!=0 && harr[parent(i)] > harr[i])
        {
            swap(harr[parent(i)],harr[i]);
            i = parent(i);
        }
    }
    
    int extractMin()
    {
        if(heap_size==0)    return -1;
        
        int temp = harr[0];
        
        harr[0] = harr[heap_size-1];
        heap_size--;
        
        MinHeapify(0);
        
        return temp;
    }
    
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        
        int smallest = i;
        
        if(l<heap_size && harr[l]<harr[i])  smallest = l;
        if(r<heap_size && harr[r]<harr[smallest])   smallest = r;
        
        if(i!=smallest)
        {
            swap(harr[i],harr[smallest]);
            heapify(smallest);
        }
    }
    
    void deleteKey(int i)
    {
        decreaseKey(i,INT_MIN);
        extractMin();
    }
    
    void decreaseKey(int i,int new_node)
    {
        harr[i] = new_node;
        while(i!=0 && harr[parent(i)] > harr[i])
        {
            swap(harr[parent(i)],harr[i]);
            i = parent(i);
        }
    }
};

signed main()
{
    
}
