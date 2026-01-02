class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char c: expression){
            if (c==',') continue;
            if (c!=')') st.push(c);
            else{
                bool t = false;
                bool f = false;
                while (st.top()!='('){
                    if (st.top()=='t') t=true;
                    if (st.top()=='f') f=true;
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();

                char res;
                if (op=='!') res=t?'f':'t';
                else if (op=='&') res=f?'f':'t';
                else res=t?'t':'f';

                st.push(res);
            }
        }
        return st.top()=='t';

    }
};