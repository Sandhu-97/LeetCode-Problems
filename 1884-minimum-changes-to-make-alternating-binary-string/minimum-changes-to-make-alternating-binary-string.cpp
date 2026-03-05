class Solution {
public:
    int minOperations(string s) {
        int count1 =0, count2=0;

        for (int i=0;i<s.size();i++){
            char opt1 = (i%2==0)?'0':'1';
            char opt2 = (i%2==0)?'1':'0';
            
            if (s[i]!=opt1) count1++;
            if (s[i]!=opt2) count2++;
        }

        return min(count1, count2);
    }
};