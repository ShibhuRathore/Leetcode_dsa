class Solution {
public:
    bool carPooling(vector<vector<int>>& trip, int capacity) {
        vector<int> result(1001,0);
        for(int i=0;i<trip.size();i++){
            int passenger=trip[i][0];
            int start=trip[i][1];
            int end=trip[i][2];
            result[start]+=passenger;
            result[end]-=passenger;
        }
        int currentpassenger=0;
        for(int i=0;i<result.size();i++){
            currentpassenger+=result[i];
            if(currentpassenger>capacity){
                return false;
            }
        }
        return true;
    }
};