class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for (int i: nums) st.insert(i);

        int maxlen=0;
        
        
        for (auto& it: st){
            if(!st.count(it-1)){
                int start=it;
                int count=1;

                while (st.count(start+1)){
                    start++;
                    count++;
                }
                maxlen = max(count, maxlen);
            }

        }
        return maxlen;
    }
};