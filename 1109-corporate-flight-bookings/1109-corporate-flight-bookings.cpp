class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
       int m=bookings.size();
      vector<int>ans(n,0);
       for(auto &vec:bookings){
        int start=vec[0]-1;
        int end=vec[1];
        int seats=vec[2];
        ans[start]+=seats;
        if(end<n){
        ans[end]-=seats;
        }
       }
       vector<int>result;
       int sum=0;
       for(int i=0;i<ans.size();i++){
        sum+=ans[i];
        result.push_back(sum);
       }
       return result;
    }
};