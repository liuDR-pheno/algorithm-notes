class Solution {
    public:
        int trap(vector<int>& h) {
            //暴力解法：每个主子上面的盛水量取决于左右侧最高的柱子的较小的一个
            int left=h[0];
            int ans=0;
            for(int i=1;i<h.size();i++){
                int right=0;
                //找左侧最高柱子
                for(int k=i-1;k>=0;k--){
                    if(h[k]>left){
                        left=h[k];
                    }
                }
                //找右侧最高
                for(int j=i+1;j<h.size();j++){
                    if(h[j]>right){
                        right=h[j];
                    }
                }
                //取最小柱子，就是他的极限
                int last=min(left,right);
                //如果极限高度比本身小或者相等，就盛不了水
                if(last<=h[i]) continue;
                if(last>h[i]) ans+=(last-h[i]);
            }
            return ans;
        }
    };

    //正确解法
    class Solution {
        public:
            int trap(vector<int>& h) {
                //提前算一遍每个位置上的左/右侧最大柱子高度，有点类似前缀和
                int len=h.size();
                int ans=0;
                vector<int> leftmax(len);
                vector<int> rightmax(len);
                leftmax[0]=h[0];
                rightmax[len-1]=h[len-1];
                for(int i=1;i<len;i++){
                    leftmax[i]=max(leftmax[i-1],h[i]);
                }
                for(int i=len-2;i>=0;i--){
                    rightmax[i]=max(rightmax[i+1],h[i]);
                }
                for(int i=0;i<len;i++){
                    int last=min(leftmax[i],rightmax[i]);
                    if(h[i]>=last) continue;
                    else{
                        ans+=(last-h[i]);
                    }
                }
                return ans;
            }
        };

//3.19重新刷
class Solution {
    public:
        int trap(vector<int>& h) {
            int n=h.size();
            vector<int> left,right(n);
            //创建数组，存放当前格子的左侧最大和右侧最大
            int height=h[0];
            for(int i=0;i<n;i++){
                int t=h[i];
                if(t>height){
                    height=t;
                }
                left.push_back(height);
            }
            int he=h[h.size()-1];
            for(int i=n-1;i>=0;i--){
                int t=h[i];
                if(t>he){
                    he=t;
                }
                right[i]=he;
            }
            //计算雨水面积
            int ans=0;
            for(int i=1;i<n-1;i++){
                int l=left[i];
                int r=right[i];
                int k=min(l,r);
                if(h[i]>=k) continue;
                else{
                    ans+=(k-h[i]);
                }
            }
            return ans;
        }
    };