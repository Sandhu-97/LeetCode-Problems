typedef long long ll;
typedef pair<ll, ll> p;
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<p> kmin;
        set<p> remaining;

        ll sum = 0;
        int i = 1;
        while (i-dist<1){
            kmin.insert({nums[i], i});
            sum+=nums[i];
            if (kmin.size()>k-1){
                p temp = *kmin.rbegin();
                sum-=temp.first;
                remaining.insert(temp);
                kmin.erase(temp);
            }
            i++;
        }

        ll res = LONG_MAX;

        while (i<n){
            kmin.insert({nums[i], i});
            sum+=nums[i];
            
            if(kmin.size()>k-1){
                p temp = *kmin.rbegin();
                sum-=temp.first;
                remaining.insert(temp);
                kmin.erase(temp);
            }

            res = min(res, sum);

            p remove = {nums[i-dist], i-dist};

            if (kmin.count(remove)){
                kmin.erase(remove);
                sum-=remove.first;
                if (!remaining.empty()){
                    p temp = *remaining.begin();
                    kmin.insert(temp);
                    sum+=temp.first;
                    remaining.erase(temp);
                }
            }
            else{
                remaining.erase(remove);
            }
            i++;
        }
        return nums[0]+res;
    }
};