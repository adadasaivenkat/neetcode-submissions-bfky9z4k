class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n);
        for(int i=0; i<n; i++){
            int res=1;
            for(int j=0; j<i; j++) res*=nums[j];
            for(int k=i+1; k<n; k++) res*=nums[k];
            v[i]=res;
        }
        return v;
    }
};
