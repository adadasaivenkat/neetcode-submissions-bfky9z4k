class Solution {
private:
    int solve(int n, int start, vector<int>& nums){
        if(n<start) return 0;
        if(n==start) return nums[start];
        int take=nums[n]+solve(n-2,start,nums);
        int notTake=solve(n-1,start,nums);
        return max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(solve(n-1,1,nums),solve(n-2,0,nums));
    }
};

// Edge case: If there is only one house, rob it directly.
// Example:
// nums = [5]
// We normally solve:
// 1) Rob houses [0...n-2] -> [0...-1] (invalid)
// 2) Rob houses [1...n-1] -> [1...0]  (invalid)
// Both cases return 0, but the correct answer is 5.
// Hence, handle the single-house case separately.
// if (n == 1) return nums[0];