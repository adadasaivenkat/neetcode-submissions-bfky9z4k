#include <cstring>
class Solution {
int dp[105];
private:
    int solve(int idx, int n, vector<int>& cost){
        if(idx==n-1) return cost[idx];
        if(dp[idx]!=-1) return dp[idx];
        int left=cost[idx]+solve(idx+1,n,cost);
        int right=cost[idx];
        if(idx+2<n) right+=solve(idx+2,n,cost);
        return dp[idx]=min(left,right);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n=cost.size();
        return min(solve(0,n,cost),solve(1,n,cost));
    }
};
