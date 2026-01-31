class Solution {
public:
    vector<int> minOperations(string boxes) {
        int total = 0;
        vector<int> loc;
        for (int i=0;i<boxes.size();i++){
            if (boxes[i]=='1') loc.push_back(i);
        }
        vector<int> res(boxes.size(), 0);
        int idx=0;
        for (int i=0;i<boxes.size();i++){
            int ans = 0;
            for (int k: loc){
                ans+=abs(k-i);
            }
            res[idx] = ans;
            idx++;
        }
        for (int k: loc) cout << k << " ";

        return res;
    }
};