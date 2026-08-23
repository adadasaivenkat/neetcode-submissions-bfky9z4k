class Solution {
private:
    int solve(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l=0,r=0,n=nums.size(),sum=0,ans=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};

// Exactly K times = at most K times - at most K - 1 times