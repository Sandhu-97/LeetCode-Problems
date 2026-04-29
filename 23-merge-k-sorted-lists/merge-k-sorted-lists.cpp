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

struct comp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for (auto node: lists){
            if (node) pq.push(node);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr=dummy;
        while (!pq.empty()){
            auto node = pq.top(); pq.pop();
            curr->next=node;
            if (node && node->next) pq.push(node->next);
            node->next=nullptr;
            curr=curr->next;
        }
        return dummy->next;
    }
};