class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        for(auto &ch:s) mpp[ch]++;
        bool odd=false;
        int cnt=0;
        for(auto &it:mpp){
            // even
            if(it.second%2==0) cnt+=it.second;
            // odd
            else if(it.second%2!=0){
                cnt+=it.second-1;
                odd=true;
            }
        }
        if(odd) return cnt+1;
        else return cnt;
    }
};