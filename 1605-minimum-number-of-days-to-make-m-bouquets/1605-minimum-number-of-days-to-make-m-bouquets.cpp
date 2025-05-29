class Solution {
public:
     bool ispossible(vector<int>& bloomDay,int day, int m , int k){
        int flowers=0;
        int bouquet=0;
      for(int i =0;i<bloomDay.size();i++){
        if(bloomDay[i]<=day){
            flowers++;
            if(flowers==k){
                bouquet++;
                flowers=0;
            }

        }else{
            flowers=0;
        }
         
      }
      return bouquet>=m;
     }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long  total=(long)m*k;
        int ans=-1;
        if(total>bloomDay.size()){
            return -1;
        }
        int left=*min_element(bloomDay.begin(),bloomDay.end());
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        while(left<=right){
            int mid=left+(right-left)/2;
            if(ispossible(bloomDay, mid, m,k)){
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