class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int size=blocks.size();
        int l=0,r=0,cnt=0,minCnt=INT_MAX;
        while(r<size){
            if(blocks[r]=='W') cnt++;
            if(r-l+1==k){
                minCnt=min(cnt,minCnt);
                if(blocks[l]=='W') cnt--;
                l++;
            }
            r++;
        }
        return minCnt;
    }
};