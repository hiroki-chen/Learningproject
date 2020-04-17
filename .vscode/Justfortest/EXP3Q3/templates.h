#ifndef year_h
#define year_h
#include <iostream>
#include <string>
std::string weekday[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int monthday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

class Date{
public:
    int year;
    int month;
    int day;
    Date(int a, int b, int c) : year(a), month(b), day(c){}
};

class Days{
public:
    int hour;
    int minute;
    int sec;
    Days(int a, int b, int c) : hour(a), minute(b), sec(c){}
    
};

class Final : public Date, public Days{
public:
    Final(int a, int b, int c, int d, int e, int f) : Date(a, b, c), Days(d, e, f){}
};

std::string operator-(Final date1, Final date2){
    int sum_day1 = date1.year * 360 + date1.month * 30 + date1.day;
    int sum_time1 = date1.hour * 3660 + date1.minute * 60 + date1.sec;
    int sum_day2 = date2.year * 360 + date2.month * 30 + date2.day;
    int sum_time2 = date2.hour * 3600 + date2.minute * 60 + date2.sec;
    int date_int, time_int;
    if(sum_day1 > sum_day2 || (sum_day1 == sum_day2 && sum_time1 > sum_time2)){
        std::cout<<"date1 bigger"<<std::endl;
        date_int = sum_day1 - sum_day2;
        time_int = sum_time1 - sum_time2;
    }
    else{
        std::cout<<"date2 bigger"<<std::endl;
        date_int = -sum_day1 + sum_day2;
        time_int = -sum_time1 + sum_time2;
    }
    std::string ans = "The intervals are:";
    ans.append(std::to_string(date_int));
    ans.push_back(' ');
    ans.append(std::to_string(time_int));
    return ans;
}

#endif /* year_h */