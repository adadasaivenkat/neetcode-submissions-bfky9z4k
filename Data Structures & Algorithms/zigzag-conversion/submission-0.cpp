class Solution {
public:
    string convert(string s, int numRows) {
        // Special case:
        // With 1 row, zigzag is the same as the original string.
        if(numRows==1) return s;
        // One string for each row.
        // We cannot use a single string because characters
        // must first be grouped row-wise.
        vector<string> rows(numRows);
        int i=0,n=s.size();
        while(i<n){
            // DOWNWARD traversal:
            // 0 -> 1 -> 2 -> ... -> numRows-1
            for(int idx=0; idx<numRows && i<n; idx++){
                rows[idx]+=s[i];
                i++;
            }
            // UPWARD traversal:
            // numRows-2 -> ... -> 2 -> 1
            for(int idx=numRows-2; idx>=1 && i<n; idx--){
                rows[idx]+=s[i];
                i++;
            }
        }
        // Read row by row to form the final answer.
        string res="";
        for(auto it:rows){
            res+=it;
        }
        return res;
    }
};

// Zigzag Pattern
// DOWN : 0 -> r-1
// UP   : r-2 -> 1
// REPEAT
// Example (r = 4):
// 0 -> 1 -> 2 -> 3 -> 2 -> 1
// 0 -> 1 -> 2 -> 3 -> 2 -> 1 ...
// Example (r = 3):
// 0 -> 1 -> 2 -> 1
// 0 -> 1 -> 2 -> 1 ...