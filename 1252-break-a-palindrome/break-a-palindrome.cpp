class Solution {
public:
    string breakPalindrome(string palindrome) {

        int n =palindrome.size();
        if (n<=1) return "";
        int count=0;
        for (int i=0;i<n/2;i++){
            if (palindrome[i]!='a'){
                palindrome[i]='a';
                count++;
                break;
            }
        }
        if (count==0) palindrome[n-1]='b'; 
        return palindrome;
    }
};