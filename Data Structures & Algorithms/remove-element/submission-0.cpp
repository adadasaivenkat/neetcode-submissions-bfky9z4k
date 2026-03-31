class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for(auto it:nums){
            if(it!=val) temp.push_back(it);
        }
        for(int i=0; i<temp.size(); i++) nums[i]=temp[i];
        return temp.size();
    }
};