class MyCalendar {
public:
map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int activeEvents=0;
        for(auto &m:mp){
            activeEvents+=m.second;
            if(activeEvents>=2){
                mp[startTime]--;
                mp[endTime]++;
                if(mp[startTime]==0)mp.erase(startTime);
                if(mp[endTime]==0)mp.erase(endTime);
                return false;
            }
        }
        return true ;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */