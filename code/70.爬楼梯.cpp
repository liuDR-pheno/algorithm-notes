class Solution {
    public:
        int climbStairs(int n) {
            //这一步的上一步要么是通过走一步来的，要么是走两步来的
            vector<int> dp(n+2);//dp存的是走到这一步的情况数 数组开大一点
            dp[0]=0;
            dp[1]=1;
            dp[2]=2;
            for(int i=3;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
            }
            return dp[n];
        }
    };