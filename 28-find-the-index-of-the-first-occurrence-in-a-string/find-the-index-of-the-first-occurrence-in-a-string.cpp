class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans=-1;
        int n1=haystack.size(), n2=needle.size();
        int i=0;

        if (n2>n1) return -1;
        
        for (;i<n1;i++){
            int j=0;
            while (i+j<n1 && j<n2 && haystack[i+j]==needle[j]){
                if (j==0) ans=i;
                j++;
            }

            if (j==n2){
                return ans;
            }
            else ans=-1;

        }
        return ans;
        
    }
};