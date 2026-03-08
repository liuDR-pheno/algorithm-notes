class Solution {
    public:
        int trap(vector<int>& h) {
            //暴力解法：每个主子上面的盛水量取决于最近的左右侧最高的柱子的较小的一个
            int left=h[0];
            int ans=0;
            for(int i=1;i<h.size();i++){
                int right=0;
                for(int k=i-1;k>=0;k--){
                    if(h[k]>left){
                        left=h[k];
                    }
                }
                for(int j=i+1;j<h.size();j++){
                    if(h[j]>right){
                        right=h[j];
                    }
                }
                int last=min(left,right);
                if(last<=h[i]) continue;
                if(last>h[i]) ans+=(last-h[i]);
            }
            return ans;
        }
    };