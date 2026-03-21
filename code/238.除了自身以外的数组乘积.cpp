/*给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除了 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。*/
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n=nums.size();
            vector<int> pre(n);
            vector<int> last(n);
            vector<int> ans(n);
            pre[0]=1;
            last[n-1]=1;
            //先计算前缀乘积
            for(int i=1;i<n;i++){
                pre[i]=pre[i-1]*nums[i-1];
            }
            //再计算后缀乘积
            for(int i=n-2;i>=0;i--){
                last[i]=last[i+1]*nums[i+1];
            }
            //答案就是前缀乘积和后缀乘积的乘积
            for(int i=0;i<n;i++){
                ans[i]=pre[i]*last[i];
            }
            return ans;
        }
    };