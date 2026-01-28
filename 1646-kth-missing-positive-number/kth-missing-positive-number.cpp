class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0, h=arr.size()-1;

        while (l<=h){
            int mid = l+(h-l)/2;
            int current_index = mid;
            int ideal_index = arr[mid]-1;
            int missing = ideal_index-current_index;
            if(missing<k) l=mid+1;
            else h=mid-1;
        }
        return k+l;
    }
};