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
        queue<int> q;
        stack<int> st;

        ListNode* curr = head;

        while (curr){
            st.push(curr->val);
            q.push(curr->val);
            curr=curr->next;
        }

        while (!st.empty() && !q.empty()){
            if (st.top()!=q.front()){
                return false;
            }
            st.pop();
            q.pop();
        }
        return true;
    }
};