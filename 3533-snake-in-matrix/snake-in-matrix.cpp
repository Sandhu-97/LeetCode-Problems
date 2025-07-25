class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i=0, j=0;

        for (string command: commands){
            if (command=="LEFT") j--;
            else if (command=="RIGHT") j++;
            else if (command=="UP") i--;
            else if (command=="DOWN") i++;
        }

        return (i*n)+j;
    }
};