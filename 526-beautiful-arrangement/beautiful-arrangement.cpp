class Solution {
public:
    int count, N;
    vector<int> temp;
    vector<bool> used;

    void solve(int curr){

        if (curr>N){
            count++;
            return;
        }
        for (int i=1;i<=N;i++){
            if (used[i]) continue;
            if (curr%i!=0 && i%curr) continue;
            used[i] = true;
            temp.push_back(i);
            solve(curr+1);
            temp.pop_back();
            used[i] = false;
        }
    }
    int countArrangement(int n) {
        count=0;
        N=n;    
        used.assign(n+1, false);    
        solve(1);
        return count;
    }
};