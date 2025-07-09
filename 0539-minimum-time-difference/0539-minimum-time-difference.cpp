class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>mins;
        for(auto &s:timePoints){
            int hour=stoi(s.substr(0,2));
            int minutes=stoi(s.substr(3,2));
            int time=hour*60+minutes;
            mins.push_back(time);
        }
        sort(mins.begin(),mins.end());
        int min_diff=INT_MAX;
        for(int i=1;i<mins.size();i++){
            int currdiff=mins[i]-mins[i-1];
            min_diff=min(min_diff,currdiff);
        }

        if(timePoints.size()>1440) return 0;
        int curr_diff=1440-(mins.back()-mins[0]);
        min_diff=min(min_diff,curr_diff);
        return min_diff;

    }
};