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
    ListNode* findMid(ListNode* head)
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

        if(prev)    prev->next = NULL;

        return slow;
    }
    ListNode* Merge(ListNode* a,ListNode* b)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;

        while(a!=NULL && b!=NULL)
        {
            if(a->val > b->val)
            {
                ptr->next = b;
                ptr = b;
                b = b->next;
            }
            else
            {
                ptr->next = a;
                ptr = a;
                a = a->next;
            }
        }

        while(a)
        {
            ptr->next = a;
            ptr = a;
            a = a->next;
        }

        while(b)
        {
            ptr->next = b;
            ptr = b;
            b = b->next;
        }

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;

        ListNode* mid = findMid(head);

        head = sortList(head);
        mid = sortList(mid);

        return Merge(head,mid);
    }
};
