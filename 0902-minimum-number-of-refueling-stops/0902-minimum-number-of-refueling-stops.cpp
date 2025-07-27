class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    //    sort(stations.begin(),stations.end());
       priority_queue<int>pq;
       int n=stations.size();
       int fuel=startFuel;
       int refuel=0;
       int i=0;
       while(fuel<target){
        while(i<n&&stations[i][0]<=fuel){
            pq.push(stations[i][1]);
            i++;
        }
        if(pq.empty())return -1;
       fuel+= pq.top();
       pq.pop();
       refuel++;
       }
       return refuel;
    }
};