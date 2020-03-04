//
//  main.cpp
//  第四章自立题14
//
//  Created by Mark on 2019/11/11.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[]) {
    int year,weekday;
    int month;
    int monthday[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
        cout<<"Input YEAR and what WEEKDAY of 1.1(0-6) in that year:";
        cin>>year>>weekday;
        cout<<"MONTH(1-12)of that year:";
        cin>>month;
    int op = weekday;
    bool flag;
            if((year % 4 == 0 && year%100!=0)||(year % 400 == 0)) flag = true;
               else flag = false;
    if(month == 1){
        cout<<"---------------------------------"<<endl;
        cout<<"SUN  MON  TUE  WED  THU  FRI  SAT"<<endl;
        cout<<"---------------------------------"<<endl;
        for (int i=1;i<=31;i++){
            if (op % 7==0){
                if(i==1){
                    cout<<setw(op*4.5)<<i<<endl;
                }
                else cout<<setw(5)<<i<<endl;
            }
            else if(op % 7 ==1){
                cout<<i;
            }
            else {
                if(i==1){
                    cout<<setw(op*4.5)<<i;
                }
                else cout<<setw(5)<<i;
            }
            op++;
        }
    }
    else{
        if(month == 2){
            if(flag){
                op = (31%7)+weekday;
                cout<<"---------------------------------"<<endl;
                cout<<"SUN  MON  TUE  WED  THU  FRI  SAT"<<endl;
                cout<<"---------------------------------"<<endl;
                for (int i=1;i<=29;i++){
                    if (op % 7==0){
                        if(i==1){
                            cout<<setw(op*4.5)<<i<<endl;
                        }
                        else cout<<setw(5)<<i<<endl;
                    }
                    else if(op % 7 ==1){
                        cout<<i;
                    }
                    else {
                        if(i==1){
                            cout<<setw(op*4.5)<<i;
                        }
                        else cout<<setw(5)<<i;
                    }
                    op++;
                }
            }
            else{
                cout<<"---------------------------------"<<endl;
                cout<<"SUN  MON  TUE  WED  THU  FRI  SAT"<<endl;
                cout<<"---------------------------------"<<endl;
                for (int i=1;i<=28;i++){
                    op = (31%7)+weekday;
                    if (op % 7==0){
                        if(i==1){
                            cout<<setw(op*4.5)<<i<<endl;
                        }
                        else cout<<setw(5)<<i<<endl;
                    }
                    else if(op % 7 ==1){
                        cout<<i;
                    }
                    else {
                        if(i==1){
                            cout<<setw(op*4.5)<<i;
                        }
                        else cout<<setw(5)<<i;
                    }
                    op++;
            }
        }
        }
        else{
            if(month == 3||month == 5||month == 7||month == 8||month == 10||month == 12){
                cout<<"SUN  MON  TUE  WED  THU  FRI  SAT"<<endl;
                cout<<"---------------------------------"<<endl;
                int sum = 0;
                for(int j=1;j<=month;j++){
                    if(j!=2) sum += monthday[j];
                    else{
                        if(flag) sum += 29;
                        else sum += 28;
                    }
                }
                for (int i=1;i<=31;i++){
                    op = (sum%7)+weekday;
                    if (op % 7==0){
                        if(i==1){
                            cout<<setw(op*4.5)<<i<<endl;
                        }
                        else cout<<setw(5)<<i<<endl;
                    }
                    else if(op % 7 ==1){
                        cout<<i;
                    }
                    else {
                        if(i==1){
                            cout<<setw(op*4.5)<<i;
                        }
                        else cout<<setw(5)<<i;
                    }
                    op++;
                }
            }
            else if(month == 4||month == 6||month == 9||month == 11){
                cout<<"---------------------------------"<<endl;
                cout<<"SUN  MON  TUE  WED  THU  FRI  SAT"<<endl;
                cout<<"---------------------------------"<<endl;
                for (int i=1;i<=30;i++){
                    int sum = 0;
                    for(int j=1;j<=month;j++){
                        if(j!=2) sum += monthday[j];
                        else{
                            if(flag) sum += 29;
                            else sum += 28;
                        }
                    }
                    op = (sum%7)+weekday;
                    if (op % 7==0){
                        if(i==1){
                            cout<<setw(op*4.5)<<i<<endl;
                        }
                        else cout<<setw(5)<<i<<endl;
                    }
                    else if(op % 7 ==1){
                        cout<<i;
                    }
                    else {
                        if(i==1){
                            cout<<setw(op*4.5)<<i;
                        }
                        else cout<<setw(5)<<i;
                    }
                    op++;
                }
            }
        }
    }
    return 0;
}
