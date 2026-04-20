class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int i: nums) st.insert(i);

        int ans = 0;
        for (int i: st){
            int curr=1;
            if (st.count(i-1)==0){
                int start=i;
                while (st.count(start+1)){
                    start++;
                    curr++;
                }
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};