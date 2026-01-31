class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
     sort(points.begin(),points.end(),[](const vector<int>&a, const vector<int>&b){
        return a[1]<b[1];
     });
     int currentend=points[0][1];
     int count=1;
     int n=points.size();
     for(int i=1;i<n;i++){
        if(points[i][0]>currentend){
            count++;
            currentend=points[i][1];
        }
       
     }
     return count;
    }
};