/*n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子中，评分更高的那个会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。*/
class Solution {
    public:
        int candy(vector<int>& ra) {
            int n = ra.size();
            if(n == 0) return 0;

            vector<int> l(n, 1), r(n, 1);
    
            // 左遍历：右边 > 左边，右边糖果+1
            for(int i=1; i<n; i++){
                if(ra[i] > ra[i-1]){
                    l[i] = l[i-1] + 1;
                }
            }
    
            // 右遍历：左边 > 右边，左边糖果+1
            for(int i=n-2; i>=0; i--){
                if(ra[i] > ra[i+1]){
                    r[i] = r[i+1] + 1;
                }
            }
    
            // 每个位置取最大值，累加总和
            int ans = 0;
            for(int i=0; i<n; i++){
                ans += max(l[i], r[i]);
            }
    
            return ans;
        }
    };