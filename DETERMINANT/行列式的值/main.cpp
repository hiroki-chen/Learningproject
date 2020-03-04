//
//  main.cpp
//  行列式的值
//
//  Created by Mark on 2019/11/18.
//  Copyright © 2019 Mark. All rights reserved.
//
#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    cout<<"Order:"<<endl;
    int order;
    cin>>order;
    cout<<"Input determinant:"<<endl;
    int dt[order][order];
    for (int i = 1; i<=order; i++) {
        for (int j = 1; j<=order; j++) {
            cin>>dt[order][order];
        }
    }
    int inverse(int,char);
    return 0;
}
int inverse(int order,char number[order]){
    int result = 0;
    for(int i = 1;i<=strlen(number[order]);i++){
        for(int j = i+1;j<=strlen(number[order]);j++){
            if(i>j) result += 1;
        }
    }
    return result;
}
