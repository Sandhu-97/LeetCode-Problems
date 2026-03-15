class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int level = 0;

        for (char c: s){
            if (c=='('){
                level++;
                if (level<=1) continue;
                ans.push_back(c);
            }

            else{
                level--;
                if (level<=0) continue; 
                ans.push_back(c);
            }
        }
        return ans;
    }
};