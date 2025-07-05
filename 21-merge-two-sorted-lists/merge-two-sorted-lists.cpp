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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        
        while (temp1 && temp2){
            ListNode* newnode;
            if (temp1->val > temp2->val){
                newnode = new ListNode(temp2->val);
                temp2 = temp2->next;
            }
            else {
                newnode = new ListNode(temp1->val);
                temp1 = temp1->next;
            }
            tail->next= newnode;
            tail=tail->next;
        }
        while (temp1){
            ListNode* newnode = new ListNode(temp1->val);
            temp1=temp1->next;
            tail->next = newnode;
            tail = newnode;
        }
        while (temp2){
            ListNode* newnode = new ListNode(temp2->val);
            temp2=temp2->next;
            tail->next = newnode;
            tail = newnode;
        }
        return dummy->next;
    }
};