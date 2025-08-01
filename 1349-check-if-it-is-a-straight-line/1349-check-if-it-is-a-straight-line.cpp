// use cross multiplication

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
       int x=coordinates[0][0];
       int y=coordinates[0][1];
       for(int i=1;i<coordinates.size()-1;i++){
       int x1=coordinates[i][0];
       int y1=coordinates[i][1];
       int x2=coordinates[i+1][0];
       int y2=coordinates[i+1][1];
       if((y1-y)*(x2-x1)!=(y2-y1)*(x1-x)){
        return false;
       }
       
       }
       return true;
    }
};