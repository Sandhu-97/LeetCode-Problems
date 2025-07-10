class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score=0;
        int i=0;
        int j=tokens.size()-1;
        int res = 0;
        while (i<=j){
            if (power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
                res = max(score, res);
            }
            else if (score>0 && power<tokens[i]){
                power+=tokens[j];
                j--;
                score--;
            }
            else break;

        }
        return res;
    }
};