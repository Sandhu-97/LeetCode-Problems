class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int earn1=0, earn2=0;
        unordered_map<int, int> mp;
        vector<int> st;
        for (int i: nums){
            mp[i]++;
        }

        for (auto it: mp) st.push_back(it.first);
        sort(st.begin(), st.end());

        for (int i: st){
            int curr = i*mp[i];
            if (mp.find(i-1)!=mp.end()){
                int temp = earn2;
                earn2 = max(curr+earn1, earn2);
                earn1 = temp;
            }
            else {
                int temp = earn2;
                earn2 = earn2+curr;
                earn1=temp;
            }
        }
        return earn2;


    }
};