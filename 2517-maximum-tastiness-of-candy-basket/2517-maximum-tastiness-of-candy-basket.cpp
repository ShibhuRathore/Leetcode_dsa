class Solution {
public:
    bool ispossible(vector<int>&price,int mid, int k){
        int currprice=price[0];
        int candies=1;
        for(auto &p:price){
            if(abs(currprice-p)>=mid){
                candies++;
                currprice=p;
            }
            if(candies>=k)return true;
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n=price.size();
        int s=0;
        int e=price[n-1]-price[0];
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(price,mid,k)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};