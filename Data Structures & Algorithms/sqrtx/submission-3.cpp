class Solution {
public:
    int mySqrt(int x) {
        long long i=1;
        int ans=0;
        while(true){
            if(i*i<=x){
                ans=i;
            }
            else if(i*i>x) break;
            i++;
        }
        return ans;
    }
};