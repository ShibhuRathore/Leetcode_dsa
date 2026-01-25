class Solution {
public:
     bool ispossible(vector<int>&weights,int days , int mid){
        int currwt=0;
        int count=1;
        for(auto &wt:weights){
            if(wt>mid)return false;
            if(currwt+wt>mid){
                currwt=wt;
                count++;
              
            }
            else{
                currwt+=wt;
            }
        }
        return (count<=days);
     }
    int shipWithinDays(vector<int>& weights, int days) {
       int s=*max_element(weights.begin(),weights.end());
       int e=accumulate(weights.begin(),weights.end(),0);
       int ans=-1;
       while(s<=e){
        int mid=s+(e-s)/2;
        if(ispossible(weights,days,mid)){
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