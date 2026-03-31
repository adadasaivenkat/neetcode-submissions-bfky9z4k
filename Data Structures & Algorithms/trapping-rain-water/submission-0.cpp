class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxWater=0;
        for(int i=0; i<n; i++){
            int leftMax=0,rightMax=0;
            for(int l=0; l<=i; l++) leftMax=max(leftMax,height[l]);
            for(int r=i; r<n; r++) rightMax=max(rightMax,height[r]);
            maxWater+=min(leftMax,rightMax)-height[i];
        }
        return maxWater;
    }
};
