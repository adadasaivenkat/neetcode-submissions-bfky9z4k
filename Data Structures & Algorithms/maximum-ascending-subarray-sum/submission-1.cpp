class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum=0;
        for(int i=0; i<nums.size(); i++){
            vector<int> inc;
            int sum=0;
            for(int j=i; j<nums.size(); j++){
                if(inc.empty()) inc.push_back(nums[j]);
                else if(!inc.empty() && inc.back()<nums[j]) inc.push_back(nums[j]);
                else break;
            }
            for(auto it:inc) sum+=it;
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};