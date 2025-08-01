class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    int i=1;
    int n=intervals.size();
    vector<vector<int>>temp;
    int s=intervals[0][0];
    int e=intervals[0][1];
    while(i<n){
        int s_b=intervals[i][0];
        int e_b=intervals[i][1];
        if(s<=e_b&&e>=s_b){
            s=min(s_b,s);
            e=max(e_b,e);
        }
        else{
        temp.push_back({s,e});
        s=s_b;
        e=e_b;
       
        }
        i++;
       
    }
    temp.push_back({s,e});
     return temp;
    }
};
