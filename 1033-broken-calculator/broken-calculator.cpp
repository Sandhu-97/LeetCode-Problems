class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count=0;
        while(target>startValue){
            if(target%2==0){
                target/=2;
            }
            else target+=1;
            count++;
        }
        return count+startValue-target;
    }
};