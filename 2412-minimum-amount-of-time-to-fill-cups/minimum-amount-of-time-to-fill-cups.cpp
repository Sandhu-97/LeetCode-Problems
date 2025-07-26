class Solution {
public:
    int fillCups(vector<int>& amount) {

        priority_queue<int> pq;
        int time=0;
        for (auto i: amount) {
            if (i!=0) pq.push(i);
        }

        while (pq.size()>=2){
            int top1 = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();

            time++;
            top1--;
            top2--;
            if (top1>0) pq.push(top1);
            if (top2>0) pq.push(top2);
        }    
        if (pq.empty()) return time;
        return time + pq.top();
    }
};