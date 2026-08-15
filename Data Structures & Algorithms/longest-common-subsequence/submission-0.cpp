#include<cstring>
class Solution {
int dp[1005][1005];
private:
    int solve(int i, int j, string& text1, string& text2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j]=1+solve(i-1,j-1,text1,text2);
        return dp[i][j]=max(solve(i,j-1,text1,text2),solve(i-1,j,text1,text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solve(text1.size()-1,text2.size()-1,text1,text2);
    }
};
