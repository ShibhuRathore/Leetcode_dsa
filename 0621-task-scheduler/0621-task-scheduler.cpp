class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto & task:tasks){
            mp[task]++;
        }
        priority_queue<int> pq;
        for(auto &freq:mp){
            pq.push(freq.second);
        }
        int time=0;
        while(!pq.empty()){
            int cycle=n+1;
            vector<int> temp;
            while(cycle>0&&!pq.empty()){
                int freq=pq.top();
                pq.pop();
                freq--;
                time++;
                cycle--;
                if(freq!=0){
                    temp.push_back(freq);
                }
            }
            for(auto & f:temp){
                pq.push(f);
            }
            if(!pq.empty()){
                time+=cycle;
            }
        }
        return time;
    }
};