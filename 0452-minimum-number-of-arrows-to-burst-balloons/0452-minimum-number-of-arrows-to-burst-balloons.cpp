class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       int arr=1;
       sort(points.begin(),points.end());
       int endpoint=points[0][1];
       for(int i=1;i<points.size()-1;i++){
          int start=points[i][0];
          int end=points[i][1];
          if(endpoint>=start&&endpoint<=end){
            endpoint=end;
          }
          else{
            arr++;
          }
       }
       return arr+1;
    }
};