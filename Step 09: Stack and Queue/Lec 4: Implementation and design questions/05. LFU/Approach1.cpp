#include <bits/stdc++.h> 

struct Node
{
    int key;
    Node* next;
    Node* prev;
    int data;
    int cnt;

    Node(int _key,int _data)
    {
        key = _key;
        data = _data;
        cnt = 1;
    }
};

struct List
{
    int size;
    Node* head;
    Node* tail;

    List()
    {
        size = 0;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode)
    {
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
        size++;
    }

    void deleteNode(Node* ptr)
    {
        Node* nextptr = ptr->next;
        Node* prevptr = ptr->prev;
        prevptr->next = nextptr;
        nextptr->prev = prevptr;
        size--;
    }
};

class LFUCache
{
    public:
        map<int,Node*> keyNode;
        map<int,List*> freqListMap;
        int maxsize;
        int minfreq;
        int currsize;

        LFUCache(int capacity)
        {
            // Write your code here.
            maxsize = capacity;
            minfreq = 0;
            currsize = 0;
        }

        void updateFreqListMap(Node* node)
        {
            keyNode.erase(node->key);
            freqListMap[node->cnt]->deleteNode(node);
            if(node->cnt==minfreq && freqListMap[node->cnt]->size == 0) minfreq++;

            List* nextList = new List();
            if(freqListMap.find(node->cnt + 1)!=freqListMap.end())
            {
                nextList = freqListMap[node->cnt + 1];
            }
            node->cnt += 1;
            nextList->addNode(node);
            freqListMap[node->cnt] = nextList;
            keyNode[node->key] = node;
        }

        int get(int key)
        {
            if(keyNode.find(key)!=keyNode.end())
            {
                Node* node = keyNode[key];
                int res = node->data;
                updateFreqListMap(node);
                return res;
            }
            else
            {
                return -1;
            }
            // Write your code here.
        }

        void put(int key, int value)
        {
            // Write your code here.
            if(maxsize==0)  return;

            if(keyNode.find(key)!=keyNode.end())
            {
                Node* node = keyNode[key];
                node->data = value;
                updateFreqListMap(node);
            }
            else{
                if(currsize==maxsize)
                {
                    List* list = freqListMap[minfreq];
                    keyNode.erase(list->tail->prev->key);
                    freqListMap[minfreq]->deleteNode(list->tail->prev);
                    currsize--;
                }

                currsize++;

                minfreq = 1;

                List* listfreq = new List();
                if(freqListMap.find(minfreq)!=freqListMap.end())
                {
                    listfreq= freqListMap[minfreq];
                }
                Node* node = new Node(key,value);
                listfreq->addNode(node);
                keyNode[key] = node;
                freqListMap[minfreq] = listfreq;
            }
        }
};
