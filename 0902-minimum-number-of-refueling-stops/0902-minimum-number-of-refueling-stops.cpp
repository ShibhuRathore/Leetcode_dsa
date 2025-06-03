class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(),stations.end());
        priority_queue<int> pq;
        int fuel=startFuel;
        int i=0;
        int refuel=0;
        while(fuel<target){
            while(i<stations.size()&&fuel>=stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }

            if(pq.empty()){
                return -1;
            }
              fuel+=pq.top();
              pq.pop();
              refuel++;
        }
        return refuel;

    }
};