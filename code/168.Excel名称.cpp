/*给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
例如：
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 */
class Solution {
    public:
        string convertToTitle(int c) {
            //这道题我们需要自己列短除法，注意判断节点（从Z->A)
            stack<char> st;
            int n=c;
            //短除法
            while(n>26){
                int t=n%26;
                n/=26;
                //判断节点，余数为0的情况，这个时候压Z进栈，同时n本身减一
                if(t==0){
                    st.push('Z');
                    n-=1;
                }else{
                    st.push('A'+t-1);//非节点情况
                }
            }
            st.push('A'+n-1);
            string ans;
            //出栈
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            return ans;
        }
    };