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
    void Middle(ListNode* &head)
    {
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;

        // return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)  return NULL;
        if(head->next->next==NULL)
        {
            head->next = NULL;
            return head;
        }
        ListNode* temp = head;
        Middle(temp);
        return head;
    }
};
