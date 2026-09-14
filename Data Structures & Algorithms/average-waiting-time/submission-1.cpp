class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long n=customers.size(),a=customers[0][0],t=customers[0][1],f=a+t,w=f-a,avg=w;
        for(int i=1; i<n; i++){
            a=customers[i][0];
            t=customers[i][1];
            if(f>a) f=f+t;
            else f=a+t;
            w=f-a;
            avg+=w;
        }
        return (double)avg/n;
    }
};