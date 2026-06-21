class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto it:s){
            if(it==']' && !stk.empty() && stk.top()=='[') stk.pop();
            else if(it=='}' && !stk.empty() && stk.top()=='{') stk.pop();
            else if(it==')' && !stk.empty() && stk.top()=='(') stk.pop();
            else stk.push(it);
        }
        return stk.empty();
    }
};
