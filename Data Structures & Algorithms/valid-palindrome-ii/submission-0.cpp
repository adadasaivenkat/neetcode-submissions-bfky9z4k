class Solution {
private:
    bool isPalindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n=s.size();
        for(int i=0; i<n; i++){
            string newStr=s.substr(0,i)+s.substr(i+1);
            if(isPalindrome(newStr)) return true;
        }
        return false;
    }
};