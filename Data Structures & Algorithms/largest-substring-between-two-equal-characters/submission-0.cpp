class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size(),mx=-1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]) mx=max(mx,j-i+1-2);
            }
        }
        return mx;
    }
};