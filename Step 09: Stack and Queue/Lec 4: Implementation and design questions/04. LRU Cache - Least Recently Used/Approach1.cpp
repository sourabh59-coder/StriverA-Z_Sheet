class LRUCache {
public:
    class Node{
        public:
            int key;
            int data;
            Node* next;
            Node* prev;

            Node(int _key,int _data)
            {
                key = _key;
                data = _data;
                next = NULL;
                prev = NULL;
            }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newnode)
    {
        Node* temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        temp->prev = newnode;
        newnode->next = temp;
    }

    void deleteNode(Node* ptr)
    {
        Node* del_prev = ptr->prev;
        Node* del_next = ptr->next;

        del_prev->next = del_next;
        del_next->prev = del_prev;
    }
    
    int get(int _key) {
        if(mp.find(_key)!=mp.end())
        {
            Node* ptr = mp[_key];
            int res = ptr->data;
            mp.erase(_key);
            deleteNode(ptr);
            addNode(ptr);
            mp[_key] = head->next;
            return res;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int _key, int value) {
        if(mp.find(_key)!=mp.end())
        {
            Node* existingNode = mp[_key];
            mp.erase(_key);
            deleteNode(existingNode);
        }

        if(mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(_key,value));
        mp[_key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
