//
//  main.cpp
//  sss
//
//  Created by Mark on 2019/12/20.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <iostream>
using namespace std;
string toLowerCase(string str) {
    unsigned long i = 0;
    while(i < str.length()){
        if('A' <= str[i]|| str[i] <= 'Z') str[i] = char(static_cast<int>(str[i])+32);
    }
    return str;
}

int main(int argc, const char * argv[]) {
    cout<<toLowerCase("Nimasile")<<endl;
    return 0;
}
