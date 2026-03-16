class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            //此题利用快慢指针，slow指针来创建我们的答案，fast用来探路
            int n=nums.size();
            if(n<=2){
                return n;
            }
            int fast=2;
            int slow=2;
            while(fast<n){
                //把快指针和慢指针的前两个元素比较，因为如果这俩一样的话，则说明这个数已经出现两次了
                if(nums[fast]==nums[slow-2]){
                    fast++;
                }else{
                    nums[slow]=nums[fast];
                    slow++;
                    fast++;
                }
            }
            return slow;
        }
    };