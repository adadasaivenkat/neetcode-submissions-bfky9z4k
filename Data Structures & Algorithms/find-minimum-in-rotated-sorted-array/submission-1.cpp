class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn=nums[0];
        for(int i=1; i<nums.size(); i++){
            mn=min(mn,nums[i]);
        }
        return mn;
    }
};