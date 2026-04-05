class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        for(auto it:operations){
            if(it=="+"){
                if(!stk.empty()){
                    int a=stk.top();
                    stk.pop();
                    int b=stk.top();
                    int c=a+b;
                    stk.push(a);
                    stk.push(c);
                }
            }
            else if(it=="C") stk.pop();
            else if(it=="D"){
                if(!stk.empty()){
                    int val=2*stk.top();
                    stk.push(val);
                }
            }
            else stk.push(stoi(it));
        }
        int sum=0;
        while(!stk.empty()){
            sum+=stk.top();
            stk.pop();
        }
        return sum;
    }
};