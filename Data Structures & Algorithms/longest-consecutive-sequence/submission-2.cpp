class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int cnt=1,maxCnt=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]==nums[i]) continue;
            else if(nums[i-1]+1==nums[i]) cnt++;
            else cnt=1;
            maxCnt=max(maxCnt,cnt);
        }
        return maxCnt;
    }
};