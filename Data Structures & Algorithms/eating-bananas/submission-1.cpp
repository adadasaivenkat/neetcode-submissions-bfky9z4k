class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxLimit=piles[0];
        for(auto it:piles) maxLimit=max(maxLimit,it);
        for(int k=1; k<=maxLimit; k++){
            long long hours=0;
            for(auto it:piles){
                hours+=ceil((double)it/k);
            }
            if(hours<=h) return k;
        }
        return maxLimit;
    }
};