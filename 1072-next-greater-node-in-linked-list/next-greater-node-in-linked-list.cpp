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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;

        ListNode* curr = head;

        while (curr){
            values.push_back(curr->val);
            curr = curr->next;
        }

        stack<int> st;
        int n = values.size();
        vector<int> res(n, 0);

        for (int i=n-1;i>=0;i--){
            while (!st.empty() && st.top()<=values[i]) st.pop();
            if (!st.empty()){
                res[i]=st.top();
            }
            st.push(values[i]);

        }
        return res;


    }
};