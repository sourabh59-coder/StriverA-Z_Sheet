class Solution {
public:
    void One(Node* head)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            Node* new_node = new Node(temp->val);
            new_node->next = temp->next;
            temp->next = new_node;
            temp = new_node->next;
        }
    }
    
    void Two(Node* head)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            if (temp->random != NULL)
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
    }
    
    Node* Three(Node* head)
    {
        Node* dummy = new Node(-1);
        Node* res = dummy;
        Node* temp = head;

        while(temp != NULL)
        {
            Node* next_node = temp->next;
            res->next = next_node;
            res = res->next;
            temp->next = next_node->next;
            temp = temp->next;
        }

        return dummy->next;
    }
    
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;  // Edge case: handle null input
        One(head);
        Two(head);
        return Three(head);
    }
};
