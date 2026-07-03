class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> v={{1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"},
        {100,"C"}, {90, "XC"}, {50,"L"}, {40,"XL"},
        {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"}};
        string res="";
        for(auto it:v){
            while(num>=it.first){
                res+=it.second;
                num-=it.first;
            }
        }
        return res;
    }
};

// Greedy Observation:
// 1. Store all Roman values in descending order.
// 2. Include the six subtractive values (IV, IX, XL, XC, CD, CM),
//    i.e., (4, 9, 40, 90, 400, 900), along with the normal Roman values
//    to handle the special Roman numeral rules.
// 3. Always choose the largest Roman value <= num.
// 4. Append its corresponding symbol to the result.
// 5. Subtract that value from num.
// 6. Repeat until num becomes 0.