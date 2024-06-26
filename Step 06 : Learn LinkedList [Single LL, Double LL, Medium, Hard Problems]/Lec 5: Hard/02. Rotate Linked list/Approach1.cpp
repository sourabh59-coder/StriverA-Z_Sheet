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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)  return head;

        int cnt = 1;

        ListNode* temp = head;

        while(temp->next!=NULL)
        {
            cnt++;
            temp = temp->next;
        }

        if(k%cnt==0)    return head;

        int val = k%cnt;

        val = cnt-val-1;

        temp->next = head;

        while(val--)
        {
            head = head->next;
        }

        ListNode* ans = head->next;
        head->next = NULL;

        return ans;
    }
};
