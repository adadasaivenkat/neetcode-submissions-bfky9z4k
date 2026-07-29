class Solution {
   public:
    int climbStairs(int n) {
        int a = 0, b = 1, sum = 0;
        for (int i = 2; i <= n + 1; i++) {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
};