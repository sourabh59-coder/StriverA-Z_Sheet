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
    ListNode* mergeKLists(vector<ListNode*>& v) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        
        priority_queue <pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> qe;

        int n = v.size();

        for(int i=0;i<n;i++)
        {
            if(v[i]!=NULL)    qe.push({v[i]->val , v[i]});
        }

        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();

            int value = it.first;
            ListNode* node = it.second;

            ListNode* temp = new ListNode(value);
            ptr->next = temp;
            ptr = ptr->next;

            if(node->next!=NULL)
            {
                qe.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};
