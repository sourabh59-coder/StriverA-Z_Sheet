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
    ListNode* kthNode(ListNode* head,int k)
    {
        k--;
        ListNode* temp = head;

        while(temp!=NULL && k>0)
        {
            temp = temp->next;
            k--;
        }

        return temp;
    }
    ListNode* reverseLL(ListNode* head)
    {
        if(head==NULL || head->next==NULL)  return head;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL)
        {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)  return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* ans = head;
        while(curr!=NULL)
        {
            ListNode* k_node = kthNode(curr,k);

            if(k_node==NULL)
            {
                if(prev)    prev->next = curr;
                break;
            }
            else
            {
                ListNode* next_node = k_node->next;
                k_node->next = NULL;
                ListNode* r_head = reverseLL(curr);
                if(prev==NULL)
                {
                    ans = r_head;
                }
                if(prev)    prev->next = r_head;
                curr->next = next_node;
                prev = curr;
                curr = curr->next;
            }
        }
        return ans;
    }
};
