class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        return nums[nums.size()-1];
    }
};