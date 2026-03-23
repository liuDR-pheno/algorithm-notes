/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。*/
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n=nums.size();
            //用队列的思想，先进先出，进的是0的位置，包括两种0，一种是遍历到的，另一种是交换后0的位置
            queue<int> q;
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    q.push(i);//遇到0，下标入队
                }else{
                    if(q.empty()) continue;//队里没有0，说明前面都不是0
                    else{
                        int pos=q.front();
                        q.pop();
                        swap(nums[i],nums[pos]);
                        q.push(i);
                    }
                }
            }
        }
    };