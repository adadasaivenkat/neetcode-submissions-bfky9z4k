class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen=INT_MIN,n=nums.size();
        for(int i=0; i<n; i++){
            vector<int> g,l;
            for(int j=i; j<n; j++){
                if(g.empty()) g.push_back(nums[j]);
                else if(!g.empty() && g.back()>nums[j]) g.push_back(nums[j]);
                else break;
            }
            for(int j=i; j<n; j++){
                if(l.empty()) l.push_back(nums[j]);
                else if(!l.empty() && l.back()<nums[j]) l.push_back(nums[j]);
                else break;
            }
            maxLen=max(maxLen,(int)max(g.size(),l.size()));
        }
        return maxLen;
    }
};