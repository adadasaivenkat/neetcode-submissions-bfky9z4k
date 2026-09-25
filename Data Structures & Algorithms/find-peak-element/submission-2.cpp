class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size(),mx=nums[0],ans=-1;
        for(int i=0; i<n; i++){
            if(nums[i]>=mx){
                mx=nums[i];
                ans=i;
            }
        }
        return ans;
    }
};