class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Take the first string as a reference.
        for(int i=0; i<strs[0].size(); i++){
            for(int j=1; j<strs.size(); j++){
                // If:
                // 1) current string is shorter (index out of range)
                // OR
                // 2) characters don't match
                // then prefix stops here
                if(i>=strs[j].size() || strs[j][i]!=strs[0][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        // If no mismatch found, entire first string is common prefix
        return strs[0];
    }
    // TC: O(N * M)  
    // where,
    // N = number of strings 
    // M = length of shortest string
    // SC: O(1)
};