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

class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        for (auto node: lists){
            if (node){
                pq.push(node);
            }
        }

        ListNode* head= new ListNode(0);
        ListNode* curr = head;

        while (!pq.empty()){
            auto node = pq.top(); pq.pop();
            curr->next = node;
            curr=curr->next;

            if (node && node->next) pq.push(node->next);
        }

        return head->next;




        
    }
};