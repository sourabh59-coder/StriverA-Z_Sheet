/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        while(node->next!=NULL)
        {
            prev = node;
            ListNode* next = node->next;
            node->val = next->val;
            node = node->next;
        }
        prev->next = NULL;
        // delete(prev);
    }
};
