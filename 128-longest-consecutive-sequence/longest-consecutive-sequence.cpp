class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int i: nums) st.insert(i);
        int ans = 0;
        for (int i: st){
            if (st.find(i-1)==st.end()){
                int count=1;
                int temp=i;
                while (st.find(temp+1)!=st.end()) {
                    count++;
                    temp++;
                }
                ans= max(ans, count);
            }
        }
        return ans;
    }
};