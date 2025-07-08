class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string opr: operations){
            if (opr=="+"){
                int num1 = st.top(); st.pop();
                int num2 = st.top();
                int result = num1+num2;
                st.push(num1);
                st.push(result);
            }
            else if (opr=="D"){
                st.push(st.top()*2);
            }
            else if (opr=="C") st.pop();
            else st.push(stoi(opr));
        }

        int res = 0;
        while (!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};