class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int count=0;
        int size=chars.size();

        if (size==1) return 1;
        for (int i=0;i<size;i++){
            int count=1;
            s.push_back(chars[i]);
            while (i<size-1&&chars[i]==chars[i+1]){
                count++;
                i++;
            }

            if (count>1) {
                string num = to_string(count);
                for (char n: num) s.push_back(n);
            }

        }
        chars.clear();
        for (char c: s){
            chars.push_back(c);
        }
        cout << s;
        return s.size();
    }
};