class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0,minVal=prices[0];
        for(int i=1; i<prices.size(); i++){
            int profit=prices[i]-minVal;
            maxProfit=max(maxProfit,profit);
            minVal=min(minVal,prices[i]);
        }
        return maxProfit;
    }
};
