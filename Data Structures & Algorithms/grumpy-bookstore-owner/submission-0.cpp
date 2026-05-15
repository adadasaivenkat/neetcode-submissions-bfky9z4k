class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int fixed=0;
        for(int i=0; i<grumpy.size(); i++){
            if(grumpy[i]==0) fixed+=customers[i];
        }
        int l=0,r=0,n=grumpy.size(),extra=0,maxExt=0;
        while(r<n){
            if(grumpy[r]==1) extra+=customers[r];
            if(r-l+1==minutes){
                maxExt=max(maxExt,extra);
                if(grumpy[l]==1) extra-=customers[l];
                l++;
            }
            r++;
        }
        return fixed+maxExt;
    }
};