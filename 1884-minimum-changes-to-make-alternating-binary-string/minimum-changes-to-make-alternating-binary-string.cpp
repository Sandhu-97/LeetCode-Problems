class Solution {
public:
    int minOperations(string s) {
        int count=0;
        int n = s.size();
        string str1, str2;
        bool alternator=true;
        for (int i=0;i<n;i++){
            if (alternator){
                str1.push_back('0');
                str2.push_back('1');
            }
            else {
                str1.push_back('1');
                str2.push_back('0');
            }

            alternator=!alternator;
        }

        cout << str1 << " " << str2 << endl;
        
        int temp1=0, temp2=0;
        for (int i=0;i<n;i++){
            if (s[i]!=str1[i]) temp1++;
            if (s[i]!=str2[i]) temp2++;
        }
        count=min(temp1, temp2);
        return count;
    }
};