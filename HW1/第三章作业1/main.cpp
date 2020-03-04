//
//  main.cpp
//  第三章作业1
//
//  Created by Mark on 2019/10/12.
//  Copyright © 2019 Mark. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    int i,j;
    int point;
    cin>>i;
    int a[i];
    for(j=1;j<=i;j++){
        cin>>a[j];
    }
    string resultodd,resulteven;
    for(j=1;j<=i;j++){
        resulteven = "";
        resultodd = "";
        for(point = 1; point <= a[j];point += 2){
            resultodd = resultodd + " " + to_string(point);
        }
        for(point = 2; point <= a[j];point += 2){
            resulteven = resulteven + " " + to_string(point);
        }
        size_t n = resulteven.find_last_not_of(" \r\n\t");
        if (n != string::npos){
            resulteven.erase(n + 1, resulteven.size() - n);
        }
        n = resulteven.find_first_not_of(" \r\n\t");
        if (n != string::npos){
            resulteven.erase(0, n);
            size_t n = resultodd.find_last_not_of(" \r\n\t");
            if (n != string::npos){
                resultodd.erase(n + 1, resultodd.size() - n);
            }
            n = resultodd.find_first_not_of(" \r\n\t");
            if (n != string::npos){
                resultodd.erase(0, n);
        }
        if(j != 1){
            cout<<endl;
            cout<<resultodd<<endl;
            cout<<resulteven<<endl;
        }
        else {
            cout<<resultodd<<endl;
            cout<<resulteven<<endl;}
    }
    }
    return 0;
}
