class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int t) {
            //使用两次二分查找。
            int n=matrix.size();//行数
            int m=matrix[0].size();//列数
            //先处理空白
            if(matrix.empty()) return 0;
            //第一次二分查找，用来寻找比目标值所在的那一层（最大的首元素比t小的
            int top=0;
            int bottom=n-1;
            int tr=-1;
            while(top<=bottom){
                int mid=top+(bottom-top)/2;
                if(matrix[mid][0]<=t){
                    tr=mid;
                    top=mid+1;
                }else{
                    bottom=mid-1;
                }
            }
            if(tr==-1) return 0;
            //第二次二分查找，来找到底有无
            int l=0;
            int r=m-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(matrix[tr][mid]==t){
                    return 1;
                }else if(matrix[tr][mid]<t){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            return 0;
        }
    };