class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> temp;
        // Store
        for(int i=n-k; i<n; i++) temp.push_back(nums[i]);
        // Shift
        for(int i=n-k-1; i>=0; i--){
            nums[i+k]=nums[i];
        }
        // Return
        for(int i=0; i<temp.size(); i++){
            nums[i]=temp[i];
        }
    }
};