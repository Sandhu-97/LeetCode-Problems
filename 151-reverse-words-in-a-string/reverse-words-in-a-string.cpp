class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;

        string temp="";
        int n = s.size();
        for (int i=0;i<n;i++){
            if (s[i]==' '){
                if (temp.size()>0) {
                    // cout << temp << endl;
                    st.push(temp);
                }
                temp="";
                continue;
            }
            temp.push_back(s[i]);
        }
        if (temp.size()>0) st.push(temp);
        string ans = "";
        while (!st.empty()){
            ans+=st.top();
            st.pop();
            if (st.size()>0)ans+=" ";
        }

        return ans;
    }
};