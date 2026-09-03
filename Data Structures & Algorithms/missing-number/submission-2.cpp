class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), arrSum = 0, totalSum = n * (n + 1) / 2;
        for (auto& it : nums) arrSum += it;
        return totalSum - arrSum;
    }
};