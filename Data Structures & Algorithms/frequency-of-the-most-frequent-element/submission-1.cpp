class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),maxFreq=0;
        for(int i=0; i<n; i++){
            int temp=k,freq=1;
            for(int j=i-1; j>=0; j--){
                int inc=nums[i]-nums[j];
                if(inc>temp) break;
                temp=temp-inc;
                freq++;
            }
            maxFreq=max(maxFreq,freq);
        }
        return maxFreq;
    }
};