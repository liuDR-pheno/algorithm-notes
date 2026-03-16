class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        //草稿纸自己写逻辑，很清楚
        int n=a.size();
        vector<vector<int>> tmp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tmp[j][n-1-i]=a[i][j];
            }
        }
        a=tmp;
    }
};