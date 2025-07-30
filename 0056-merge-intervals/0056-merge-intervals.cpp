class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>>res;
    sort(intervals.begin(),intervals.end());
    int n=intervals.size();
    int start_a=intervals[0][0];
    int end_a=intervals[0][1];
    for(int i=1;i<n;i++){
    int start_b=intervals[i][0];
    int end_b=intervals[i][1];
    if(start_a<=end_b&&start_b<=end_a){
        start_a=min(start_a,start_b);
        end_a=max(end_a,end_b);
 

    }else{
        res.push_back({start_a,end_a});
        start_a=start_b;
        end_a=end_b;
    }}
      res.push_back({start_a,end_a});
        return res;
    }
};
