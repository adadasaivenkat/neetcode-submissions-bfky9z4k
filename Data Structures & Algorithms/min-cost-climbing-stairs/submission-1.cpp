#include <cstring>
class Solution {
int dp[105];
private:
    int solve(int n, vector<int>& cost){
        if(n==0 || n==1) return cost[n];
        if(dp[n]!=-1) return dp[n];
        int left=cost[n]+solve(n-1,cost);
        int right=cost[n]+solve(n-2,cost);
        return dp[n]=min(left,right);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n=cost.size();
        return min(solve(n-2,cost),solve(n-1,cost));
    }
};
