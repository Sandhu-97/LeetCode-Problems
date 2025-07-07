class Solution {
public:
    int minLength(string s) {
        // string res;
        // for (char c: s){
            
        //     if (c=='B' && res.size()>0 && res.back()=='A' ) res.pop_back();
        //     else if (c=='D' && res.size()>0 && res.back()=='C') res.pop_back();
        //     else res.push_back(c);
        // }
        // return res.size();

        stack<char> st;

        for (char c: s){
            
            if (!st.empty() && c=='B' && st.top()=='A') st.pop();
            else if (!st.empty() && c=='D' && st.top()=='C') st.pop();
            
            else st.push(c);
        }
        return st.size();
    }
};