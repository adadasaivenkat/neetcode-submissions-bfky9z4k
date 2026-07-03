class Solution {
public:
    string intToRoman(int num) {
        string ones[10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundreds[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousands[4]={"","M","MM","MMM"};
        return thousands[num/1000]+hundreds[(num%1000)/100]+tens[(num%100)/10]+ones[num%10];
    }
};

// Observation:
// 1. Each decimal place (Ones, Tens, Hundreds, Thousands) has a fixed
//    Roman numeral representation.
// 2. Store all possible representations for each place value in separate arrays.
// 3. Extract each digit of num and use it as an index into the corresponding array.
// 4. Concatenate the results from Thousands, Hundreds, Tens, and Ones.