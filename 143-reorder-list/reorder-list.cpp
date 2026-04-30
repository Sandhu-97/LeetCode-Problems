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
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;

        while (fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* prev=nullptr;
        while (slow){
            ListNode* temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }

        ListNode* first=head;
        ListNode* second=prev;

        while (second && second->next){
            ListNode* temp=first->next;
            first->next=second;
            first=temp;

            temp=second->next;
            second->next=first;
            second=temp;
        }

    }
};