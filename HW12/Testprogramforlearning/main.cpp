//
//  main.cpp
//  Testprogramforlearning
//
//  Created by Mark on 2019/12/17.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <iostream>
#include <array>
using namespace std;
void print(int a[]){
    cout<<*(a+1)<<endl;
}
int main(int argc, const char * argv[]) {
    double a1[4][5];
    double a2[4];
    double (*pa1)[5] = a1; //将二维数组赋予数组指针。 因为全部“指向”数组。
    double *pa2 = a2; //将数组赋予了指针。 全部指向普通零维元素。
    double *pa3[4] = {};
    double** ppa3 = pa3; //将指针数组赋予了二重指针，因为全部“指向”指针！
    return 0;
}

