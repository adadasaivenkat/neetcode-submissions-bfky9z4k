class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            int a=nums[i];
            int b=target-a;
            if(mpp.find(b)!=mpp.end()) return {mpp[b],i};
            mpp[nums[i]]=i;
        }
        return {};
    }
};