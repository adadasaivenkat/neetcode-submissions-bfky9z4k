class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,n=s.size(),maxFreq=INT_MIN,maxLen=INT_MIN;
        unordered_map<char,int> mpp;
        while(r<n){
            mpp[s[r]]++;
            maxFreq=max(maxFreq,mpp[s[r]]);
            while((r-l+1)-maxFreq>k){
                mpp[s[l]]--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);  // windowSize - maxFrequency <= k
            r++;
        }
        return maxLen;
    }
};