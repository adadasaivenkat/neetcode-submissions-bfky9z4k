class Solution {
private:
    void fun(int idx, vector<int>& nums, int n, 
    int sum, int target, int &cnt){
        if(idx==n){
            if(sum==target) cnt++;
            return;
        }
        fun(idx+1,nums,n,sum+nums[idx],target,cnt);
        fun(idx+1,nums,n,sum-nums[idx],target,cnt);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt=0;
        fun(0,nums,nums.size(),0,target,cnt);
        return cnt;
    }
};
