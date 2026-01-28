class Solution {
public:
    int calc(vector<int>& pos, int dist){
        int count=1;
        int prev = pos[0];
        for (int i=1;i<pos.size();i++){
            if (pos[i]-prev>=dist) {
                count++;
                prev=pos[i];
            }
        }
        return count;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int low=1;
        int high=pos.back()-pos.front();

        while (low<=high){
            int mid = (low+high) >> 1;
            int calcBalls = calc(pos, mid);
            if (calcBalls>=m){
                low = mid+1;
            }
            else high=mid-1;

        }
        return high;
    }
};