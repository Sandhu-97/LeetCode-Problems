class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();

        int top = 0;
        int left = 0;
        int down = m - 1;
        int right = n - 1;

        int dir = 1;
        while (top <= down && left <= right) {

            for (int i = left; i <= right; i++)
                ans.push_back(mat[top][i]);
            top++;

            for (int i = top; i <= down; i++)
                ans.push_back(mat[i][right]);
            right--;

            if (top <= down) {
                for (int i = right; i >= left; i--)
                    ans.push_back(mat[down][i]);
                down--;
            }

            if (left <= right) {
                for (int i = down; i >= top; i--)
                    ans.push_back(mat[i][left]);
                left++;
            }
        }
        return ans;
    }
};