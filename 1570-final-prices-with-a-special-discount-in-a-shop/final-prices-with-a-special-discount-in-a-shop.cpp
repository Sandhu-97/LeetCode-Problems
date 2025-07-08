class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;

        for (int i = prices.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();  // we want smaller or equal
            }

            int discount = st.empty()?0:st.top();
            prices[i]-=discount;
            st.push(prices[i]+discount);  // push current price (after discount)
        }

        return prices;
    }
};
