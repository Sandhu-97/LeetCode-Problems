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

    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head->next;
        st.push(head);
        while (temp){

            while (!st.empty() && temp->val>(st.top())->val){
                st.pop();
            }
            st.push(temp);
            temp=temp->next;
        }
        ListNode* nxt = nullptr;

        while (!st.empty()){
            ListNode* newnode = st.top();
            st.pop();
            newnode->next = nxt;
            nxt=newnode;
        }
        return nxt;
    }
};