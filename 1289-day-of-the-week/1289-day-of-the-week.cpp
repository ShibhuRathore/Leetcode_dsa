class Solution {
public:
    bool isLeapYear(int year){
        if(year%400==0)return true;
        if(year%100==0)return false;
        if(year %4==0)return true;
        return false;
    }
    string dayOfTheWeek(int day, int month, int year) {
        vector<string>weeks={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        vector<int>days={31,28,31,30,31,30,31,31,30,31,30,31};
        int base_day=5;
        
        for(int years=1971;years<year;years++){
            int total_days=0;
            for(int months=0;months<12;months++){
             total_days+=days[months];
            }
            if(isLeapYear(years)){
                total_days++;
             }
            base_day=(total_days+base_day)%7;
        }
        for(int months=0;months<month-1;months++){
            base_day+=days[months];
        }
        if(isLeapYear(year)&&month>2){
            base_day++;
        }
        base_day=(base_day+day-1)%7;
        return weeks[base_day];
    }
};