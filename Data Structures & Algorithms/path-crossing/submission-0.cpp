class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        int x=0,y=0;
        st.insert({x,y});
        for(auto it:path){
            if(it=='N') y++;
            else if(it=='S') y--;
            else if(it=='E') x++;
            else if(it=='W') x--;
            if(st.count({x,y})) return true;
            st.insert({x,y});
        }
        return false;
    }
};