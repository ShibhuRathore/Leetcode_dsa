class Solution {
public:
int MOD=1e9+7;
    long long kadanes(vector<int>arr){
        long long currsum=0;
        long long  maxsum=INT_MIN;
        for(auto &ele:arr){
            currsum=max(currsum+ele,(long long)ele);
            maxsum=max(maxsum,currsum);
        }
        return maxsum<0?0:maxsum;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        long long  totalsum=0;
        for(auto &ele:arr){
            totalsum+=ele;
        }
        vector<int>temp(2*n,0);
        for(int i=0;i<2*n;i++){
            temp[i]=arr[i%n];
        }
        long long two_max=kadanes(temp);
        long long  one_max=kadanes(arr);
        if(k>1){
        if(totalsum>0)return ((k-2)*totalsum + two_max)%MOD;
        else return two_max%MOD;
        }
        return one_max%MOD;
    }
};