class Solution {
public:
    bool winnerOfGame(string colors) {
        int count_a = 0;
        int count_b = 0;
        if (colors.size()<=2) return false;

        for (int i=1;i<colors.size()-1;i++){
            if (colors[i-1]=='A' && colors[i]=='A' && colors[i+1]=='A') count_a++;
            else if (colors[i-1]=='B' && colors[i]=='B' && colors[i+1]=='B') count_b++;
        }
        return count_a>count_b;
    }
};