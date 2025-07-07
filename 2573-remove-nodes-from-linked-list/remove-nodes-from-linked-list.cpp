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

    ListNode* reverse(ListNode* head){
        if (!head || !head->next) return head;
        ListNode* newHead = reverse(head->next);
        head->next->next= head;
        head->next = nullptr;
        return newHead;
    }
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* temp = head->next;
        st.push(head->val);
        while (temp){

            while (!st.empty() && temp->val>st.top()){
                st.pop();
            }
            st.push(temp->val);
            temp=temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!st.empty()){
            ListNode* newnode = new ListNode(st.top());
            st.pop();
            tail->next = newnode;
            tail=newnode;
        }
        return reverse(dummy->next);
    }
};