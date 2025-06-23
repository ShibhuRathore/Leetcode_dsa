class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>adj;//key=stops//value={indices}
        if(source==target){
            return 0;
        }
        for(int route=0;route<routes.size();route++){
            for(auto&stop:routes[route]){
                adj[stop].push_back(route);
            }
        }
        queue<int>q;
        vector<bool>visited(501,false);
        for(auto&route:adj[source]){
            q.push(route);
            visited[route]=true;
        }
        int busCount=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int route=q.front();
                q.pop();
                for(auto &stop:routes[route]){
                    if(stop==target){
                        return busCount;
                    }
                    for(auto &nextRoute:adj[stop]){
                        if(visited[nextRoute]==false){
                            visited[nextRoute]=true;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};