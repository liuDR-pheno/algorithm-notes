/*给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。*/
class Solution {
    public:
        //重载cmp函数,直接比较两个连在一起谁大，这样子排序
        static bool cmp(int a,int b){
            string fa=to_string(a);
            string fb=to_string(b);
            return fa+fb>fb+fa;
        }
        string largestNumber(vector<int>& nums) {
            string ans;
            sort(nums.begin(),nums.end(),cmp);
            if(nums[0]==0){
                return "0";
            }
            for(int i=0;i<nums.size();i++){
                ans+=to_string(nums[i]);
            }
            return ans;
        }
    };
    //重点是重载cmp函数，直接比较两个连在一起谁大，这样子排序