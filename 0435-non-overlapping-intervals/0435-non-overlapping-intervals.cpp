class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),[](const vector<int>&a, const vector<int>&b){
        return a[1]<b[1];
    });
    int count=0;
     int endpoint =intervals[0][1];
    for(int i=1;i<intervals.size();i++){
        int start=intervals[i][0];
        int end=intervals[i][1];
        if(start<endpoint){
            count++;
        }
        else{
             endpoint=end;
        }
    }
    return count;
    }
};