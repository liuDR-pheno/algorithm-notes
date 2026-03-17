/*给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。*/
class Solution {
    public:
        string reverseWords(string s) {
            //这次利用栈，直接存string，目的是从前往后放单词
            stack<string> st;
            int n=s.size();
            string word;
            string ans;
            //从前往后便利
            for(int i=0;i<n;i++){
                //如果遇到空格，且单词不为空，那么压入栈
                if(s[i]==' '&&!word.empty()){
                    st.push(word);
                    word.clear();
                }
                //如果遇到字母，那么加到word里
                if(s[i]!=' '){
                    word+=s[i];
                }
            }
            //切记，word中可能还有内容，并没有压入栈
            if(!word.empty()){
                st.push(word);
            }
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                    ans+=" ";
                }
            if(!ans.empty()){
                ans.pop_back();
            }
            return ans;
        }
    };