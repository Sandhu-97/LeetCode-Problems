class Solution {
public:
    const int MAXI = INT_MAX;
    const int MINI = INT_MIN;

    int solve(int i, string s, long long num, int sign){
        if (i>=s.size() || !isdigit(s[i])){
            return (int)(sign*num);
        }

        num = num*10+(s[i]-'0');

        if (sign*num>=MAXI) return MAXI;
        if (sign*num<=MINI) return MINI;

        return solve(i+1, s, num, sign);
    }

    int myAtoi(string s) {
        int n = s.size();
        int i=0;

        while (i<n && s[i]==' ') i++;
        int sign=1;

        if (i<n && (s[i]=='+' || s[i]=='-')){
            sign = (s[i]=='-')?-1:1;
            i++;
        }
        return solve(i, s, 0, sign);
    }
};