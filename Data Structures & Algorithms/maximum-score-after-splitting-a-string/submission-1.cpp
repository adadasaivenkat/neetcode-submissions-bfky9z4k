class Solution {
public:
    int maxScore(string s) {
        int n=s.size(),maxScore=INT_MIN,ones=0,zeroes=0;
        for(auto it:s) ones+=(it=='1' ? 1 : 0);
        for(int i=0; i<n-1; i++){
            if(s[i]=='0') zeroes++;
            else ones--;
            maxScore=max(maxScore,zeroes+ones);
        }
        return maxScore;
    }
};