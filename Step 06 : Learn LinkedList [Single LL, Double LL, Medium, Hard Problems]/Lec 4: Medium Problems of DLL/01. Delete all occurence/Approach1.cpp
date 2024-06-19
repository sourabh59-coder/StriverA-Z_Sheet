/**
 * Definition of doubly linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here+
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == k)
        {
            if(temp==head)
            {
                head = head->next;
                temp = temp->next;
            }
            else
            {
                Node* prev_node = temp->prev;
                Node* next_node = temp->next;

                prev_node->next = next_node;
                if(next_node)    next_node->prev = prev_node;
                temp = next_node;
            }
        }
        else    temp = temp->next;
    }
    return head;
}
