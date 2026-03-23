/*给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。*/
class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            int n=nums.size();
            //使用贪心算法，让最小的值一直更小
            int small=INT_MAX;
            int mid=INT_MAX;
            for(int i=0;i<n;i++){
                int cur=nums[i];
                if(cur<=small){//如果比最小值还小，那就更新最小值
                    small=cur;
                }else if(cur<=mid){//如果比中间值还小，那就更新中间值
                    mid=cur;
                }else if(cur>mid){//如果比中间值还大，那就返回true
                    return 1;
                }
            }
            return 0;
        }
    };