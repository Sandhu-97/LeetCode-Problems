class Solution {
public:
    int calcDays(vector<int>& weights, int days){
        int count=1;
        int cur=0;
        for (int w: weights){
            if( cur+w>days){
                count++;
                cur=0;
            }
            cur+=w;
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low<high){
            int mid = low+(high-low)/2;
            int calcdays = calcDays(weights, mid);
            if (calcdays>days) low=mid+1;
            else high=mid;
        }
        return low;
    }
};