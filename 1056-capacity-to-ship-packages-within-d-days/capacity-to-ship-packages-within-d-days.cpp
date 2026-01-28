class Solution {
public:
    int calcDays(vector<int>& weights, int capacity){
        int count=1;
        int cur=0;
        for (int w: weights){
            if( cur+w>capacity){
                count++;
                cur=0;
            }
            cur+=w;
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0, high=0;
        for (int w: weights){
            low = max(low, w);
            high+=w;
        }
        int ans =0;
        while (low<=high){
            int mid = low+(high-low)/2;
            int calcdays = calcDays(weights, mid);
            if (calcdays<=days) {
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};