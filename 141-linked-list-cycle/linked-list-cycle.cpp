/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        unordered_map<ListNode*, bool> mp;
        ListNode* curr = head;
        while (curr){
            if (mp[curr]) return true;
            mp[curr] = true;
            curr = curr->next;

        }
        return false;
    }
};