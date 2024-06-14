/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        head = temp;
        ListNode* ptr = head;
        for(int i=0;i<n;i++)
        {
            ptr = ptr->next;
        }
        ListNode* node = head;
        while(ptr->next!=NULL)
        {
            node = node->next;
            ptr = ptr->next;
        }
        node->next = node->next->next;
        return head->next;
    }
};
