class Solution {
public:
    int maxScore(string s) {
        int n=s.size(),maxScore=INT_MIN;
        vector<int> pref(n,0),suff(n,0);
        if(s[0]=='0') pref[0]=1;
        for(int i=1; i<n; i++) pref[i]=pref[i-1]+(s[i]=='0' ? 1 : 0);
        if(s[n-1]=='1') suff[n-1]=1;
        for(int i=n-2; i>=0; i--) suff[i]=suff[i+1]+(s[i]=='1' ? 1 : 0);
        for(int i=0; i<n-1; i++){
            maxScore=max(maxScore,pref[i]+suff[i+1]);
        }
        return maxScore;
    }
};