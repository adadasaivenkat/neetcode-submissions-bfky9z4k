class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        int l=0,r=0,n=s.size();
        unordered_map<char,int> mpp;
        while(r<n){
            while(mpp.count(s[r])){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            mpp[s[r]]++;
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};