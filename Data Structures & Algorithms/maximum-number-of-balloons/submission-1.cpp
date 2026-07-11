class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        for(auto it:text) mpp[it]++;
        int cnt=0;
        while(true){
            if(mpp['b']<1 || mpp['a']<1 || mpp['l']<2 || mpp['o']<2 || mpp['n']<1) break;
            mpp['b']-=1;
            mpp['a']-=1;
            mpp['l']-=2;
            mpp['o']-=2;
            mpp['n']-=1;
            cnt++;
        }
        return cnt;
    }
};