/*给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。*/
class Solution {
    public:
        //把十进制转换成二进制,并统计1的个数
        int change(int x){
            int ans=0;
            while(x){
                int c=x%2;
                if(c==1) ans++;
                x/=2;
            }
            return ans;
        }
        vector<int> countBits(int n) {
            vector<int> ans;
            for(int i=0;i<=n;i++){
                int s=change(i);
                ans.push_back(s);
            }
            return ans;
        }
    };