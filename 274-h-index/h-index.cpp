class Solution {
public:
    int hIndex(vector<int>& cit) {
        sort(cit.begin(), cit.end());
        int left = 0;
        int n = cit.size();
        int right=n-1;

        while (left<=right){
            int mid = (left+right) >> 1;
            if (cit[mid]>=n-mid){
                right=mid-1;
            }
            else left=mid+1;
        }
        return n-left;
    }
};