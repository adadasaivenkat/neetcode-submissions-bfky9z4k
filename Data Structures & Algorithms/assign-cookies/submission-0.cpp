class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size();
        int m=s.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                j++;
                i++;
            }
            else j++;
        }
        return i;
    }
};

// Take this example for better understanding...
// Student (g) = [1,5,3,3,4]
// Cookie (s) = [4,2,1,2,1,3]