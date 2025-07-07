class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (char i: s){
            if (st.empty() || st.top().first != i){
                st.push({i, 1});
            }
            else{
                auto top = st.top();
                st.pop();
                st.push({i, top.second+1});
            }
            if (st.top().second==k){
                st.pop();
            }
        }

        string res;

        while (!st.empty()){
            auto top = st.top();
            st.pop();
            while (top.second--){
                res.push_back(top.first);
            }
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};