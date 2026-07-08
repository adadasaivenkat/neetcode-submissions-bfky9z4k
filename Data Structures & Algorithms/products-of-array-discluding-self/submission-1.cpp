class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n);
        for(int i=0; i<n; i++){
            int res=1;
            for(int j=0; j<n; j++){
                if(i!=j) res*=nums[j];
            }
            v[i]=res;
        }
        return v;
    }
};