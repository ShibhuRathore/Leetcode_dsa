//  If (Sum of all Gas) - (Sum of all Cost) >= 0, and you found a starting point that can reach the end of the array without hitting zero, it is mathematically impossible to fail the remaining part of the circle.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int totalgas=0;
      int totalcost=0;
      int fuel=0;
      int start=0;
      int n=gas.size();
      for(int i=0;i<n;i++){
        totalgas+=gas[i];
        totalcost+=cost[i];
        fuel=fuel+gas[i]-cost[i];
        if(fuel<0){
            fuel=0;
            start=i+1;
        }
      }
      return totalgas>=totalcost?start:-1;
    }
};
