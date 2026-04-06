class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        for(auto it:nums){
            if(it!=0) temp.push_back(it);
        }
        for(int i=0; i<temp.size(); i++) nums[i]=temp[i];
        for(int i=temp.size(); i<nums.size(); i++) nums[i]=0;
    }
};