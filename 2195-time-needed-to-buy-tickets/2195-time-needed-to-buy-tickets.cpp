class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    deque<pair<int,int>>dq;
    for(int i=0;i<tickets.size();i++){
       dq.push_back({i,tickets[i]});
    }
    int time=0;
    while(1){
        pair<int,int>P=dq.front();
        dq.pop_front();
        int i=P.first;
        int ticket=P.second;
        time++;
        ticket--;
        if(i==k&&ticket==0){
            return time;
        }
        if(ticket>0){
            dq.push_back({i,ticket});
        }
    }
    return -1;
    }
};