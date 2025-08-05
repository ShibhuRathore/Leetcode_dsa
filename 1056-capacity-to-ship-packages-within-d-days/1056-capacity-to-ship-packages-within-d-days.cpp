class Solution {
public:
    bool isPossible(vector<int>&weights,int capacity,int days){
        int day=1;
        int currweight=0;
        for(auto &wt:weights){
            if (wt > capacity) return false;
            if(wt+currweight>capacity){
                day++;
                currweight=wt;
                if (day > days) return false;
            }
          
            else{
                currweight+=wt;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
      int s=1;
      int e=accumulate(weights.begin(),weights.end(),0);
      int mid=s+(e-s)/2;
      int ans=-1;
      while(s<=e){
        if(isPossible(weights,mid,days)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
      }
      return ans;
    }
};