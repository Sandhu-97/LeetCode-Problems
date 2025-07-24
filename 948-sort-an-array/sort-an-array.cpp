class Solution {
public:


    void merge(vector<int>& nums, int low, int mid, int high){
        if (low>=high) return;
        int l = low;
        int r = mid+1;
        int k=0, size=high-low+1;

        vector<int> sorted(size, 0);
        while (l<=mid && r<=high){
            sorted[k++] = nums[l]<nums[r]?nums[l++]:nums[r++];
        }
        while (l<=mid) sorted[k++] = nums[l++];
        while (r<=high) sorted[k++] = nums[r++];

        for (k=0;k<size;k++) nums[k+low] = sorted[k];
        
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if (low>=high) return;
        int mid = low + (high-low)/2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};