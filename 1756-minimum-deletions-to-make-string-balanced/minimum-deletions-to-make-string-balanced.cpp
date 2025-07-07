class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count=0;
        for (char i:s){
            if (i=='b') st.push(i);
            else if (!st.empty() && i=='a') {
                st.pop();
                count++;
            }
        }
        return count;
        
    }
};