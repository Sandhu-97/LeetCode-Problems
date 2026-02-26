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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev = nullptr;
        if (!head->next) return nullptr;
        while (fast && fast->next){
            fast=fast->next;   
            n--;
            if (n<=0) {
                prev=slow;
                slow=slow->next;
            }
        }
        
        if (prev && prev->next) prev->next = prev->next->next;
        else if (!prev) head=head->next;
        return head;

    }
};