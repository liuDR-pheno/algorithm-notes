/*给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回 该列名称对应的列序号 。
例如：
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...*/
class Solution {
    public:
        int titleToNumber(string c) {   
            //其实就是26进制转换
            long long ans = 0;  // 用 long long 防止溢出
            for (char ch : c) { // 直接遍历每个字符（从左到右）
                ans = ans * 26 + (ch - 'A' + 1); // 核心公式
            }
            return (int)ans;
        }
    };