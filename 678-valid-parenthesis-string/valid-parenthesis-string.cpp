class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;
        int n =s.size();


        for (char c: s){
            if (c=='(') {
                min_open++;
                max_open++;
            }
            else if(c==')'){
                min_open--;
                max_open--;
            }
            else if(c=='*'){
                min_open--;
                max_open++;
            }

            if (min_open<0){
                min_open=0;
            }
            if (max_open<0) return false;
        }
        return (min_open==0);
    }
};