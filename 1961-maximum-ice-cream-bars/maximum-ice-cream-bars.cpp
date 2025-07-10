class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count=0;
        for (int c: costs){
            if (coins>=c){
                coins-=c;
                count++;
            }
            else break;
        }
        return count;
    }
};