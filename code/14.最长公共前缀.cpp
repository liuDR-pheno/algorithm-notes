/*编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。*/
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int n=strs.size();
            int m_len=10000000;
            string ans;
            for(int i=0;i<n;i++){
                if(strs[i].size()<m_len){
                    m_len=strs[i].size();
                }
            }
            for(int i=0;i<m_len;i++){
                bool f=1;
                char c=strs[0][i];
                for(int j=0;j<n;j++){
                    if(strs[j][i]!=c){
                        f=0;
                        break;
                    } 
                }
                if(f==1) ans+=c;
                else{
                    break;
                }
            }
            return ans;
        }
    };