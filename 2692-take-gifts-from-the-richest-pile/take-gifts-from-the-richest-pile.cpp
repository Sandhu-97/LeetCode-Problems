#include <cmath>

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (int i: gifts) pq.push(i);

        long long sum = 0;

        while (k--){
            int top = pq.top();
            pq.pop();
            pq.push(floor(sqrt(top)));
        }

        while (!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;

        
    }
};