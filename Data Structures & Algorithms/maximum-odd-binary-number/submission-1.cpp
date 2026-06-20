class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0;
        for(auto it:s){
            if(it=='1') ones++;
        }
        int zeroes=s.size()-ones;
        string ans="";
        ans+=string(ones-1,'1');
        ans+=string(zeroes,'0');
        ans+='1';
        return ans;
    }
};

// Key Observation
// An odd binary number must end with '1'.
// To maximize the binary number, place as many '1's as possible at the beginning.
// Keep exactly one '1' for the last position.
// Put all '0's in between.
// Example
// s = "0110"
// count1 = 2
// count0 = 2
// Result = "1" + "00" + "1" = "1001"