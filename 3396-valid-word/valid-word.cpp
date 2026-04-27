class Solution {
public:
    bool is_vowel(char c){
        c=tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    bool isValid(string word) {
        int csts=0;
        int vows=0;
        for (char c: word){
            if (!isalnum(c)) return false;
            else if (isalpha(c)){
                if (is_vowel(c)) vows++;
                else csts++;
            }
        }
        return word.size()>=3 && csts>0 && vows>0;
    }
};