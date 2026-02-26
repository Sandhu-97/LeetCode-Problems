class Solution {
public:
    int numSteps(string s) {
        int carry=0, ans=0;
        for (int i=s.size()-1;i>0;i--){
            if (s[i]-'0' + carry==1){
                ans+=2;
                carry=1;
            }
            else ans++;
        }
        return ans+carry;
    }
};