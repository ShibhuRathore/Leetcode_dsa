class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>merge;
        int n=intervals.size();
        int i=0;
        
        while(i<n&&intervals[i][1]<newInterval[0]){
         // non overlapping -keep moving i
           merge.push_back({intervals[i][0],intervals[i][1]});
           i++;
        }
       
        while(i<n&&intervals[i][1]>=newInterval[0]&&intervals[i][0]<=newInterval[1]){
           newInterval[0]=min(intervals[i][0],newInterval[0]);
             newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        merge.push_back(newInterval);
         while(i<n){
         // non overlapping -keep moving i
           merge.push_back({intervals[i][0],intervals[i][1]});
           i++;
        }
     return merge;
    }
};