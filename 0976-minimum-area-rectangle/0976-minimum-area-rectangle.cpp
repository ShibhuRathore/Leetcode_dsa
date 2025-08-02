class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>>mp;
        for(auto &p:points){
            int x1=p[0];
            int y1=p[1];
            mp[x1].insert(y1);
        }
        int minarea=INT_MAX;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int x1=points[i][0], y1=points[i][1];
                int x2=points[j][0], y2=points[j][1];
                if(x1!=x2&&y1!=y2){
                    if(mp[x1].count(y2)&&mp[x2].count(y1)){
                       int area=abs(x2-x1)*abs(y2-y1);
                       minarea=min(minarea,area);
                    }
                }
            }
        }
        return minarea==INT_MAX?0:minarea;
    }
};