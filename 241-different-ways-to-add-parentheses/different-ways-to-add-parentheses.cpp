class Solution {
public:
    vector<int> solve(string exp, unordered_map<string, vector<int>>& mp){
        vector<int> res;

        if (mp.count(exp)) return mp[exp];
        for (int i=0;i<exp.size();i++){
            if (exp[i]=='+' || exp[i]=='-' || exp[i]=='*'){
                vector<int> left = solve(exp.substr(0, i), mp);
                vector<int> right = solve(exp.substr(i+1), mp);

                for (int x: left){
                    for (int y: right){
                        if (exp[i]=='+') res.push_back(x+y);
                        else if (exp[i]=='*') res.push_back(x*y);
                        else if (exp[i]=='-') res.push_back(x-y);
                    
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(exp));
        return mp[exp]=res;
        
    }
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> mp;
        return solve(expression, mp);   
    }
};