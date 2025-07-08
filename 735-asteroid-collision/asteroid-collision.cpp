class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int& i: asteroids){
            while (!st.empty() && st.top()>0 && i<0){
                int sum = st.top()+i;
                if (sum>0){
                    i=0;
                }
                else if (sum<0){
                    st.pop();
                }
                else {
                    i=0;
                    st.pop();
                }
            }
            if (i!=0) st.push(i);
        }
        vector<int> arr;
        while (!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};