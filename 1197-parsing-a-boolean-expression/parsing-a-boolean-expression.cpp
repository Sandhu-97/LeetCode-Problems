class Solution {
public:

    bool parse(int& i, string exp){
        if (exp[i]=='t') {
            i++;
            return true;
        }
        if (exp[i]=='f'){
            i++;
            return false;
        }

        char op = exp[i];
        i+=2;
        
        if (op=='!'){
            bool curr = parse(i, exp);
            i++;
            return !curr;
        }

        bool res = (op=='&')? true : false;

        while (true){
            bool curr = parse(i, exp);
            if (op=='&') res&=curr;
            else res|=curr;

            if (exp[i]==')'){
                i++;
                break;
            }
            i++;
        }
        return res;
    }
    bool parseBoolExpr(string expression) {
        int i = 0;
        return parse(i, expression);
    }
};