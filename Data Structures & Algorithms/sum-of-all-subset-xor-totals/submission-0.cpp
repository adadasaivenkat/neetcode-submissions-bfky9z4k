class Solution {
private:
    void fun(int idx, vector<int>& nums, int n, int xorr, int &total){
        if(idx==n){
            total+=xorr;
            return;
        }
        fun(idx+1,nums,n,xorr^nums[idx],total);
        fun(idx+1,nums,n,xorr,total);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int total=0;
        fun(0,nums,nums.size(),0,total);
        return total;
    }
};