class MyCalendarThree {
public:
map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
       int maxi=0;
        int sum=0;
        for(auto&m:mp){
            sum+=m.second;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */