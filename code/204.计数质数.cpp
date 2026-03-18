/*给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。*/
class Solution {
    public:
        int countPrimes(int n) {
            //使用埃氏筛
            vector<bool> isprime(n+1,1);//判断是不是质数
            isprime[1]=0;
            for(int i=2;i<sqrt(n);i++){
                if(isprime[i]){//如果i是质数的话，那么就把他的所有倍数都从质数名单中删掉
                    for(int j=i*i;j<n;j+=i){
                    isprime[j]=0;
                    }
                }
            }
            int ans=0;
            for(int i=1;i<n;i++){
                if(isprime[i]) ans++;
            }
            return ans;
        }
    };