class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        arr[0] = nums[0];
        for (int i=1;i<n;i++){
            arr[i] = arr[i-1]+nums[i];
        }

        for (int i=0;i<n;i++){
            int leftsum=0, rightsum=0;
            if (i==0) {
                leftsum=0;
                rightsum=arr[n-1]-arr[i];
            }
            else if (i==n-1){
                rightsum=0;
                leftsum = arr[n-2];
            }
            else{
                leftsum = arr[i-1];
                rightsum = arr[n-1] - arr[i];
            }


            if (leftsum==rightsum) return i;
        }
        return -1;
        
    }
};