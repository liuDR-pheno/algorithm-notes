class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> a(n,vector<int>(n));
            int left=0;
            int right=n-1;
            int up=0;
            int down=0;
            int index=1;
            while(index<n*n){
                for(int i=left;i<=right;i++){
                    a[up][i]=index++;
                }
                up--;
                for(int i=up;i<=down;i++){
                    a[i][right]=index++;
                }
                right--;
                for(int i=right;i>=left;i--){
                    a[down][i]=index++;
                }
                down--;
                for(int i=down;i>=up;i--){
                    a[i][left]=index++;
                }
                left++;
            }
            return a;
        }
    };