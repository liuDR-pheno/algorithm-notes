class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            vector<int> ans;
            //先把第一个放进去
            ans.push_back(nums[0]);
            //循环这个数组，如果当前和上一个数值不同，那我就把他push进去，一样我就跳过
            for(int i=1;i<nums.size();i++){
                if(nums[i]==nums[i-1]) continue;
                else ans.push_back(nums[i]);
            }
            int k=ans.size();
            nums=ans;
            return k;
        }
    };