class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& n) {
            //先对数组排序
            sort(n.begin(),n.end());
            vector<vector<int>> res;
            //外层循环进行i的遍历，我们只固定i，然后寻找合适的j k，但是注意要去重！
            for(int i=0;i<n.size();i++){
                int l=i+1;
                int r=n.size()-1;
                if(i!=0&&n[i]==n[i-1]) continue;
                while(l<r){
                    int tmp=n[i]+n[l]+n[r];
                    if(tmp<0) l++;
                    else if(tmp>0) r--;
                    else{
                        vector<int> cur;
                        cur.push_back(n[i]);
                        cur.push_back(n[l]);
                        cur.push_back(n[r]);
                        res.push_back(cur);
                        while(l < r&&n[l+1]==n[l]) l++;
                        while(l < r&&n[r-1]==n[r]) r--;
                        //一定要注意继续移动左右指针，不然还是卡死在同一个位置
                        l++;
                        r--;
                    }
                }
            }
            return res;
        }
    };
    //3.18复习
    class Solution {
        public:
            vector<vector<int>> threeSum(vector<int>& nums) {
                int n=nums.size();
                sort(nums.begin(),nums.end());
                vector<vector<int>> ans;
                for(int i=0;i<n;i++){
                    int l=i+1;
                    int r=n-1;
                    if(i!=0&&nums[i]==nums[i-1]) continue;//去重，重复的直接删掉
                    while(l<r){
                        int t=nums[i]+nums[l]+nums[r];
                        if(t<0) l++;
                        else if(t>0) r--;
                        else{
                            ans.push_back({nums[i],nums[l],nums[r]});
                            //注意！也许还有等于零的情况呢，rl也得动，而且！动的时候还得去重
                            while(l<r&&nums[l+1]==nums[l]) l++;
                            while(l<r&&nums[r-1]==nums[r]) r--;
                            r--;
                            l++;
                        }
                    }
                }
                return ans;
            }
        };