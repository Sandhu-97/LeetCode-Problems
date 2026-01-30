class Solution {
public:
    string solve(int& i, string& s){
        string result="";

        while (i<s.size() && s[i]!=']'){
            if (isalpha(s[i])){
                result+=s[i];
                i++;
            }

            else {
                int num = 0;
                while (isdigit(s[i])){
                    num = num*10 + (s[i]-'0');
                    i++;
                }

                i++;
                string inner = solve(i, s);
                i++;

                while (num--)result+=inner;
            }
        }
        return result;
    }
    string decodeString(string s) {
        int i = 0;
        return solve(i, s);
    }
};