class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=1;
        int e=arr.size()-2;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
         if(arr[mid]>arr[mid+1]){
            ans=mid;
            e=mid-1;
         }
         else{
            s=mid+1;
         }

        }
        return ans;
    }
};