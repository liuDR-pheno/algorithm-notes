/*给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

*/
class Solution {
    public:
        //堆化（大根堆，堆顶是max）
        //n->堆大小，i->要调整的结点下标
        void heapify(vector<int>& a,int n,int i){
            int largest=i;//假设父节点是最大值
            int left=2*i+1;
            int right=2*i+2;
            if(left<n&&a[left]>a[largest]){
                largest=left;
            }
            if(right<n&&a[right]>a[largest]){
                largest=right;
            }
            if(largest!=i){
                swap(a[i],a[largest]);
                heapify(a,n,largest);//重新调整被影响的堆
            }
        }
        int findKthLargest(vector<int>& a, int k) {
            //堆排序（nlogn）
            //数组首下标是0
            int n=a.size();
            //从后往前调整
            for(int i=n/2-1;i>=0;i--){
                heapify(a,n,i);
            }
            //取堆顶，进行排序
            for(int i=n-1;i>0;i--){
                swap(a[0],a[i]);//最大值放到末尾
                heapify(a,i,0);
            }
            return a[n-k];
        }
    };                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        