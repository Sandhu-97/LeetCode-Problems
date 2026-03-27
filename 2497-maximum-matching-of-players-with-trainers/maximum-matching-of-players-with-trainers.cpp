class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int m = players.size();
        int n= trainers.size();

        int i=m-1, j=n-1;

        while (i>=0 && j>=0){
            if (players[i]<=trainers[j]){
                i--;
                j--;
                ans++;
            }
            else i--;
        }

        return ans;
    }
};