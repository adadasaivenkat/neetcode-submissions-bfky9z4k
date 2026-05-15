class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int fixed=0;
        for(int i=0; i<grumpy.size(); i++){
            if(grumpy[i]==0) fixed+=customers[i];
        }
        int n=grumpy.size(),maxExt=0;
        for(int i=0; i<n; i++){
            int extra=0;
            for(int j=i; j<n; j++){
                if(grumpy[j]==1) extra+=customers[j];
                if(j-i+1==minutes) maxExt=max(maxExt,extra);
                else if(j-i+1>minutes) break;
            }
        }
        return fixed+maxExt;
    }
};