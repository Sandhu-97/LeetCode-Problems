class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int total_odd = 0;
        for (int& i: nums){
            if (i%2!=0) {
                total_odd++;
                i=1;
            }
            else i=0;
        }
        
        if (total_odd<k) return 0;
        int sum=0, ans=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        for (int i: nums){
            sum+=i;
            if (mp.find(sum-k)!=mp.end()) ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};