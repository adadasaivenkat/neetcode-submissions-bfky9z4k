class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp={{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int res=0;
        for(int i=0; i<s.size(); i++){
            if(i+1<s.size() && mpp[s[i]]<mpp[s[i+1]]){
                res+=mpp[s[i+1]]-mpp[s[i]];
                i++;
            }
            else res+=mpp[s[i]];
        }
        return res;
    }
};

// Observations:
// 1. Roman numerals are generally written from left to right in decreasing order.
// 2. If the current numeral is smaller than the next numeral, they form a subtractive pair (IV, IX, XL, XC, CD, CM).
// 3. For a subtractive pair, add (next - current) and skip the next character.
// 4. Otherwise, simply add the value of the current numeral.