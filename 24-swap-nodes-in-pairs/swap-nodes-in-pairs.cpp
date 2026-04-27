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
    ListNode* swapPairs(ListNode* head) {

        if (!head) return head;
        ListNode* prevNode=nullptr;
        ListNode* curr=head;
        bool swap=false;
        while(curr){
            if (swap){
                int temp=prevNode->val;
                prevNode->val=curr->val;
                curr->val=temp;
            }
            prevNode=curr;
            curr=curr->next;
            swap=!swap;
        }
        return head;
    }
};