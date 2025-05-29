class Solution {
public:
   bool ispossible(vector<int> &piles, int h , int k){
    int time=0;
    for(auto &pile:piles){
        time+=(pile+k-1)/k;
        if(time>h){
            return false;
        }
    }
    return time<=h;
   }
    
    int minEatingSpeed(vector<int>& piles, int h) {
       int left=1;
       int right=*max_element(piles.begin(),piles.end());
       int ans=right;
       while(left<=right){
        int mid=left+(right-left)/2;
         if(ispossible(piles,h,mid)){
               ans=mid;
               right=mid-1;
         }
         else{
             left=mid+1;
         }
       } 
       return ans;
    }
};