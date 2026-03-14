class Solution {
public:
    vector<string> all;
    string curr;
    void generate(int n){
        if (n==0){
            all.push_back(curr);
            return;
        }

        for (char ch='a';ch<='c';ch++){
            if (curr.empty() || curr.back()!=ch) {
                curr.push_back(ch);
                generate(n-1);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {

        generate(n);
        for (string i: all) {
            cout << i << endl;
        }
        if (k>all.size()) return "";
        return all[k-1];
    }
};