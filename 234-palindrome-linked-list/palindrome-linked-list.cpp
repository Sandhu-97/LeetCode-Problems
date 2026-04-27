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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr=head;
        while (curr){
            st.push(curr);
            curr=curr->next;
        }
        curr=head;

        while(curr){
            ListNode* top = st.top();
            st.pop();
            if (top->val!=curr->val) return false;
            curr=curr->next; 
        }
        return true;
    }
};