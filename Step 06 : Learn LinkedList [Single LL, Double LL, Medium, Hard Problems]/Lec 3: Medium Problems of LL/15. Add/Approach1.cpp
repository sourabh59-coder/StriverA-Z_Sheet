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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* head = new ListNode(-1);
        ListNode* ptr = head;
        int carry = 0;
        while (head1 && head2) {
            int val = head1->val + head2->val + carry;
            int a = val % 10;
            carry = val / 10;
            ListNode* temp = new ListNode(a);
            ptr->next = temp;
            ptr = ptr->next;

            head1 = head1->next;
            head2 = head2->next;
        }
        while (head1) {
            int val = head1->val + carry;
            int a = val % 10;
            carry = val / 10;
            ListNode* temp = new ListNode(a);
            ptr->next = temp;
            ptr = ptr->next;

            head1 = head1->next;
        }
        while (head2) {
            int val = head2->val + carry;
            int a = val % 10;
            carry = val / 10;
            ListNode* temp = new ListNode(a);
            ptr->next = temp;
            ptr = ptr->next;

            head2 = head2->next;
        }
        if (carry) {
            ListNode* temp = new ListNode(carry);
            ptr->next = temp;
            carry = 0;
        }
        head = head->next;
        return head;
    }
};
