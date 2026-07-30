class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0,r=0,n=s2.size(),cnt=0;
        unordered_map<char,int> mpp;
        for(auto &it:s1) mpp[it]++;
        while(r<n){
            if(mpp[s2[r]]>0) cnt++;
            mpp[s2[r]]--;
            if(cnt==s1.size()) return true;
            if((r-l+1)==s1.size()){
                mpp[s2[l]]++;
                if(mpp[s2[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return false;
    }
};
