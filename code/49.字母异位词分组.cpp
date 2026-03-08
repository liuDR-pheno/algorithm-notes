class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            int n=strs.size();
            vector<vector<string>> ans;
            //用哈希表来记录
            unordered_map<string,vector<string>> mp;//key是排序后的唯一的词，作为标识，value是能被加进去的单词
            for(string s:strs){
                string tmp=s;
                sort(s.begin(),s.end());//排序后他就是唯一的了
                //下面的句子有两个作用：1.如果没有key，那么就设置一个新的把他加进去 2.如果有key 直接加单词
                mp[s].push_back(tmp);
            }
            for(auto& entry:mp){//注意这里的遍历要加&，效率高
                ans.push_back(entry.second);
            }
            return ans;
        }
    };