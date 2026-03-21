/*编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。*/
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            //线性查找
            //从右上角开始查，如果target比当前值大，就往下查找，如果比当前小，就往左
            int m=matrix.size();
            int n=matrix[0].size();
            int i=0,j=n-1;
            while(i<m&&j>=0){
                if(matrix[i][j]==target){
                    return 1;
                }else if(matrix[i][j]>target){
                    j--;
                }else{
                    i++;
                }
            }
            return 0;
        }
    };