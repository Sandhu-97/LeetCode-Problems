class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans=0;

        for (string s: operations){


            if (s=="+"){
                int score1 = st.top(); st.pop();
                int score2 = st.top();

                st.push(score1);
                st.push(score1+score2);
            }

            else if (s=="D"){
                st.push(st.top()*2);
            }

            else if (s=="C") st.pop();
            else st.push(stoi(s));
        }

        while (!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};