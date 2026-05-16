class Solution {
private:
    bool fun(int idx, vector<int>& nums, int n){
        if(idx==n-1) return true;
        for(int i=1; i<=nums[idx]; i++){
            if(fun(idx+i,nums,n)) return true;
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return fun(0,nums,nums.size());
    }
};