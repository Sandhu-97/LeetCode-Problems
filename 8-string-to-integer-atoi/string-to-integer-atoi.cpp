class Solution {
public:
    int myAtoi(string s) {
        long long num=0;
        int n = s.size();
        int i=0;
        while (i<n && s[i]==' ') i++; 
        int sign=1;
        if (i<n && (s[i]=='+' || s[i]=='-')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }

        for (;i<n;i++){
            if (isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            else break;

            if (sign*num>=INT_MAX) return INT_MAX;
            if (sign*num<=INT_MIN) return INT_MIN;
        }
        
        return (int)sign*num;

    }
};