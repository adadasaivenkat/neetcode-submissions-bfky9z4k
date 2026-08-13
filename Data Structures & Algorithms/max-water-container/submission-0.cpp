class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1,maxArea=0;
        while(l<r){
            int width=r-l,height=min(heights[l],heights[r]);
            int area=width*height;
            maxArea=max(area,maxArea);
            if(heights[l]<heights[r]) l++;
            else if(heights[r]<=heights[l]) r--;
        }
        return maxArea;
    }
};
