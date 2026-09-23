class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,n=s.size(),mostFreq=INT_MIN,mxLen=INT_MIN;
        unordered_map<char,int> mpp;
        while(r<n){
            mpp[s[r]]++;
            mostFreq=max(mostFreq,mpp[s[r]]);
            if((r-l+1)-mostFreq>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            if((r-l+1)-mostFreq<=k) mxLen=max(mxLen,r-l+1);
            r++;
        }
        return mxLen;
    }
};
