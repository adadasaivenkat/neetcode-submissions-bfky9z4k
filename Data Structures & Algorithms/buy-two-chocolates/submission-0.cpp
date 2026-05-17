class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int leftOverMoney=money-prices[0]-prices[1];
        if(leftOverMoney<0) return money;
        else return leftOverMoney;
    }
};