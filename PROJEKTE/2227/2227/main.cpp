#include<iostream>
using namespace std;

class Time
{
public:
    void show_time(Time);
    Time(int a, int b, int c){
        hour = a;
        minute = b;
        sec = c;
    }
private:
    int hour;
    int minute;
    int sec;
};

void Time::show_time(Time t)
{
    cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    Time t(a,b,c);
    t.show_time(t);
}
