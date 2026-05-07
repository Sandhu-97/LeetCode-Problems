class Solution {
public:
    vector<string> all;
    string curr;
    string result="";;
    int count=0;
    
    void generate(int n, int k){
        if (curr.size()>=n) {
            count++;
            if (count==k) result=curr;
            all.push_back(curr);
            return;
        }

        for (char c='a';c<='c';c++){

            if (result!="") return;
            if (curr.empty() || curr.back()!=c) {
                curr.push_back(c);
                generate(n, k);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        generate(n, k);
        if (k>all.size()) return "";
        return all[k-1];

    }
};