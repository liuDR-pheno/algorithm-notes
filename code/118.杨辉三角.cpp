class Solution {
    public:
        vector<vector<int>> generate(int n) {
            //简单动态规划，写出状态转移方程：dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            //当i==0或者i==j值设为一
            vector<vector<int>> dp;
            for(int i=0;i<n;i++){
                vector<int> cur(i+1,0);
                dp.push_back(cur);
                for(int j=0;j<=i;j++){
                    //注意i==0或者i==j的情况
                    if(j==0) dp[i][j]=1;
                    else if(j==i) dp[i][j]=1;
                    else{
                        
                        dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                    }
                }
            }
            return dp;
    
        }
    };