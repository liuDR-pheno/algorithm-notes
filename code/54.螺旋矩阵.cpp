class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int n=matrix.size();
            int m=matrix[0].size();
            vector<int> ans;
            int l_b=0;
            int r_b=m-1;
            int u_b=0;
            int d_b=n-1;
            int x=0,y=0;
            while(ans.size()<m*n){
                for(int i=l_b;i<=r_b;i++){
                    if (ans.size() >= m * n)
                        return ans;
    
                    ans.push_back(matrix[u_b][i]);
                }
                u_b++;
                for(int i=u_b;i<=d_b;i++){
                    if (ans.size() >= m * n)
                        return ans;
    
                    ans.push_back(matrix[i][r_b]);
                }
                r_b--;
                for (int i = r_b; i >= l_b; i--) {
                    if (ans.size() >= m * n)
                        return ans;
    
                    ans.push_back(matrix[d_b][i]);
                }
                d_b--;
                // 上
                for (int i = d_b; i >= u_b; i--) {
                    if (ans.size() >= m * n)
                        return ans;
    
                    ans.push_back(matrix[i][l_b]);
                }
                l_b++;
            }
            return ans;
        }
    };//这道题完全就是草稿纸上写逻辑，代码实现