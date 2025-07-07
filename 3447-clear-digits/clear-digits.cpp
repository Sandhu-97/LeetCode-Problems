class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char c: s){
            if (isalpha(c)){
                st.push(c);
            }
            if (isdigit(c) && !st.empty()){
                st.pop();
            }
        }
        s="";
        while (!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};