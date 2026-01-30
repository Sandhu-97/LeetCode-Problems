class Solution {
public:
    int count;
    vector<int> temp;
    vector<int> nums;
    // bool valid (vector<int>& perm){
    //     int i = 1;
    //     for (int p: perm){
    //         if (p%i!=0 && i%p!=0) return false;
    //         i++;
    //     }
    //     return true;
    // }
    
    void solve(){
        if (nums.size()==0){
            // if (valid(temp)){
            //     count++;
            // }
            count++;
            return;
        }

        for (int i=0;i<nums.size();i++){
            int curr=nums[i];
            if (curr % (temp.size()+1) !=0 && (temp.size()+1) %curr !=0) continue;
            nums.erase(nums.begin()+i);
            temp.push_back(curr);
            solve();
            temp.pop_back();
            nums.insert(nums.begin()+i, curr);
        }
    }
    int countArrangement(int n) {
        count=0;
        for (int i=1;i<=n;i++) nums.push_back(i);

        solve();
        return count;
    }
};