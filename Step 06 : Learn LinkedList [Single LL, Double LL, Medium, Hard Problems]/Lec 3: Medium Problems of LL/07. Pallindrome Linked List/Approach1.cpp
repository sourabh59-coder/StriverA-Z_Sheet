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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* ptr = head;

        while(ptr!=NULL)
        {
            ListNode* temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)  return true;
        ListNode* temp;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* ptr_temp = reverseList(temp);

        while(head && ptr_temp)
        {
            if(head->val != ptr_temp->val)  return false;
            head = head->next;
            ptr_temp = ptr_temp->next;
        }

        return true;
    }
};
