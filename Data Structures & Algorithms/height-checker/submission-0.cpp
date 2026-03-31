class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp=heights;
        sort(temp.begin(),temp.end());
        int i=0;
        int size=heights.size(); // int size=temp.size();
        int cnt=0;
        while(i<size){
            if(heights[i]!=temp[i]) cnt++;
            i++;
        }
        return cnt;
    }
};