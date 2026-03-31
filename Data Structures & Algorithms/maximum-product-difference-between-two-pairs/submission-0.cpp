class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=(nums[nums.size()-1]*nums[nums.size()-2])-(nums[1]*nums[0]);
        return res;
    }
};