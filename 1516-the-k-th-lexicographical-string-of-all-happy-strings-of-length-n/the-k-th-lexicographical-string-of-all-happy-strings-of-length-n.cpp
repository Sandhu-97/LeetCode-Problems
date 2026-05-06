class Solution {
public:
    vector<string> all;
    string curr;
    void generate(int n){
        if (curr.size()>=n) {
            all.push_back(curr);
            return;
        }

        for (char c='a';c<='c';c++){
            if (curr.empty() || curr.back()!=c) {

            curr.push_back(c);
            generate(n);
            curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        generate(n);
        if (k>all.size()) return "";
        return all[k-1];
        return "";

    }
};