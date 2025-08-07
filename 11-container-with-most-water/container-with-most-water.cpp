class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int ans = 0;
        while (left<right){

            int area = min(height[right], height[left]) * (right - left);

            ans = max(area, ans);

            if (height[right]<height[left]) right--;
            else left++;
        }

        return ans;
    }
};