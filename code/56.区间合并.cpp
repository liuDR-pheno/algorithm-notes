class Solution {
    typedef pair<int,int> PII;
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n=a.size();
        vector<PII> arr;
        for(int i=0;i<n;i++){
            arr.push_back({a[i][0],a[i][1]});
        }
        sort(arr.begin(),arr.end());
        int i=1;
        vector<vector<int>> ans;
        int st=arr[0].first,ed=arr[0].second;
        while(i<n){
            int s=arr[i].first;
            int e=arr[i].second;
            //不连续的直接把上一段压进去
            if(s>ed){
                ans.push_back({st,ed});
                st=s;
                ed=e;
            }else{   //连续的话，找右侧的最大值作为ed的值
                ed=max(e,ed);  //这句是关键，
            }
            i++;
        }
        ans.push_back({st,ed});
        return ans;
    }
};