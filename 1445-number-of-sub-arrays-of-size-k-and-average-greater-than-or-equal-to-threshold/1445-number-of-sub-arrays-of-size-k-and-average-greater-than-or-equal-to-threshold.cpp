class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
       int count=0;
       int n=arr.size();
       int windowsum=0;
       for(int i=0;i<k;i++){
        windowsum+=arr[i];
       } 
       int i=0;
       if(windowsum>=k*threshold)count++;
       for(int j=k;j<n;j++){
        windowsum-=arr[i];
        i++;
        windowsum+=arr[j];
        if(windowsum>=k*threshold)count++;
       }
       return count;
    }
};