class Solution {
private:
    int solve(int n, vector<int>& cost){
        if(n==0 || n==1) return cost[n];
        int left=cost[n]+solve(n-1,cost);
        int right=cost[n]+solve(n-2,cost);
        return min(left,right);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return min(solve(n-2,cost),solve(n-1,cost));
    }
};
