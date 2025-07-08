class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
 
        for (string i: tokens){

            if (i=="+" || i=="-" || i=="*" || i=="/"){
                int result = 0;
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                if (i=="+") result = num1+num2;
                else if (i=="-") result = num1-num2;
                else if (i=="*") result = num1*num2;
                else if (i=="/") result = num1/num2;
                st.push(result);
                }
            else st.push(stoi(i));
        }
        return (st.top());
    }
};