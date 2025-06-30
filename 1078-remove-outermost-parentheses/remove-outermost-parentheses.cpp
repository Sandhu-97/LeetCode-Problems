class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        stack<char> st;

        for (char i: s){
            if (st.empty()){
                st.push(i);
            }
            else{
                if (i=='(') {
                    st.push(i);
                    result+='(';
                }
                else if (i==')'){
                    st.pop();
                    if (!st.empty()) result+=i; 
                }
            }
        }
        return result;
    }
};