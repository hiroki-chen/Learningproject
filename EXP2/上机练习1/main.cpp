//
//  main.cpp
//  上机练习1
//
//  Created by Mark on 2019/10/14.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    char ch;
    cout<<"请输入一个字符：";
    cin>>ch;
    if ((static_cast<int>(ch)<=90 && static_cast<int>(ch) >=65) || (static_cast<int>(ch)<=122 && static_cast<int>(ch)>=97)) {
        cout<<"该字符为字母。"<<endl;
    }
    else if(static_cast<int>(ch)>=48 && static_cast<int>(ch)<=57){
        cout<<"该字符为数字"<<endl;
    }
    else cout<<"该字符为其他字符。"<<endl;
    return 0;
}
