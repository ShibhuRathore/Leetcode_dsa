class MyCalendarTwo {
        map<int,int>mp;
public:
    MyCalendarTwo() {
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int activeEvents=0;
        for(auto &m:mp){
            int bookings= m.second;
            activeEvents+=bookings;
            if(activeEvents>=3){
                mp[startTime]--;
                mp[endTime]++;
                if(mp[startTime]==0)mp.erase(startTime);
                if(mp[endTime]==0)mp.erase(endTime);
                return false;
            }
        }
            return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */