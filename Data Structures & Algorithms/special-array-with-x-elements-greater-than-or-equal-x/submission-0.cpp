class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        for(int x=0; x<=n; x++){
            int cnt=0;
            for(auto it:nums){
                if(it>=x) cnt++;
            }
            if(cnt==x) return x;
        }
        return -1;
    }
};