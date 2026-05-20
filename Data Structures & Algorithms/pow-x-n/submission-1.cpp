class Solution {
private:
    double fun(double x, int n, double res){
        if(n==0) return res;
        return fun(x,n-1,res*x);
    }
public:
    double myPow(double x, int n) {
        if(n<0) return 1/fun(x,-n,1);
        else return fun(x,n,1);
    }
};