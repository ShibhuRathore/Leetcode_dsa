class Solution {
public:
    bool ispossible(vector<int>&weights, int capacity, int days){
        int sum=0;
        int day=1;
        for(auto &weight:weights){
            if(sum+weight>capacity){
                    day++;
                    sum=0;
            }
            sum+=weight;
        }
        if (day<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()); // min capacity needed
        int right = accumulate(weights.begin(), weights.end(), 0); // max capacity
        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(ispossible(weights,mid,days)){
               right=mid-1;
               ans=mid;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};