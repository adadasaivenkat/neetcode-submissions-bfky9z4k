#include <cstring>
class Solution {
int dp[105];
private:
    int solve(int n, vector<int>& nums){
        if(n<0) return 0;
        if(n==0) return nums[n];
        if(dp[n]!=-1) return dp[n];
        int take=nums[n]+solve(n-2,nums);
        int notTake=solve(n-1,nums);
        return dp[n]=max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return solve(n-1,nums);
    }
};