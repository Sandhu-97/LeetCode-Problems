class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int ans = 0;

        for (char c: s){
            if (c=='b') st.push(c);
            else if(c=='a' && !st.empty()){
                st.pop();
                ans++;
            }
        }
        return ans;
    }
};