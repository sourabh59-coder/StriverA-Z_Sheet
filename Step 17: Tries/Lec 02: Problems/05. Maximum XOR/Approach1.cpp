#include <bits/stdc++.h>

struct Node{
    Node* links[2]; // Changed size to 2 for binary characters '0' and '1'
    bool flag = false;

    Node() {
        links[0] = links[1] = NULL;
        flag = false;
    }

    bool containKey(char ch)
    {
        return links[ch - '0'] != NULL;
    }

    Node* getNext(char ch)
    {
        return links[ch - '0'];
    }

    void put(char ch, Node* new_node)
    {
        links[ch - '0'] = new_node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Tries
{
    public:
    Node* root;

    Tries(){    root = new Node();}

    void InsertNode(int val)
    {
        Node* node = root;

        char word;

        for(int i=31;i>=0;i--)
        {
            if((1<<i & val)!=0)
            {
                word = '1';
            }
            else
            {
                word = '0';
            }

            if(!node->containKey(word))
            {
                node->put(word,new Node());
            }
            node = node->getNext(word);
        }

        // for(int i=0;i<word.size();i++)
        // {
            
        // }

        node->setEnd();
    }

    int xorValue(int value)
    {
        int val = 0;

        Node* node = root;

        char word;

        for(int i=31;i>=0;i--)
        {
            if((1<<i & value)!=0)
            {
                word = '1';
            }
            else
            {
                word = '0';
            }

            char bit = (word=='1') ? '0':'1';
            
            if(node->containKey(bit))
            {
                int add = 1<<i;
                val = val | add;
                node = node->getNext(bit);
            }

            else    node = node->getNext(word);
        }

        return val;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here.   
    Tries obj;
    for(int i=0;i<arr1.size();i++)
    {
        obj.InsertNode(arr1[i]);
    }

    int ans = 0;

    for(int i=0;i<arr2.size();i++)
    {
        int val = obj.xorValue(arr2[i]);
        ans = max(ans,val);
    }

    return ans;
}
