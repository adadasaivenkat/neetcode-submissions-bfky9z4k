class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++) mpp[nums[i]]=i;
        for(int i=0; i<nums.size(); i++){
            int a=nums[i];
            int b=target-a;
            if(mpp.count(b) && mpp[b]!=i) return {i,mpp[b]};
        }
        return {-1,-1};
    }
};
