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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<>> pq;

        for (auto node: lists){
            while (node){
                pq.push(node->val);
                node=node->next;
            }
        }

        if (pq.empty()) return nullptr;

        ListNode* head = new ListNode(pq.top());
        ListNode* curr=head;

        pq.pop();
        while (!pq.empty()){
            int val = pq.top(); pq.pop();
            curr->next=new ListNode(val);
            curr=curr->next;
        }
        return head;
        
    }
};