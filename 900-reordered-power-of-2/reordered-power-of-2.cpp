class Solution {
public:

    vector<int> freq(int n){
        vector<int> freq(10);

        while (n){
            int digit = n%10;
            freq[digit]++;
            n/=10;
        }

        return freq;
    }

    bool equalFreq(vector<int>& freq1, vector<int> freq2){
        for (int i=0;i<10;i++){
            if (freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
    bool reorderedPowerOf2(int n) {
        
        vector<int> target= freq(n);

        for (int i=0;i<=30;i++){
            int po2 = (int)pow(2, i);

            if (equalFreq(target, freq(po2))) return true;
        }

        return false;
    }
};