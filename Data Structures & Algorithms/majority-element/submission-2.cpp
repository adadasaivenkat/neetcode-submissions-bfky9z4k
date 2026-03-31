class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size=nums.size()/2;
        for(int i=0; i<nums.size(); i++){
            int cnt=1;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]==nums[j]) cnt++;
            }
            if(cnt>size) return nums[i];
        }
        return -1;
    }
};