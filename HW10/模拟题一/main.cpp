//
//  main.cpp
//  模拟题一
//
//  Created by Mark on 2019/12/16.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int pingguo(int m, int n){
    if(m == 0 || n == 1) return 1;
    else if(m < n)
        return pingguo(m,m);
    else return pingguo(m,n-1) + pingguo(m-n,n);
}

int main(int argc, const char * argv[]) {
    int m,n;
    cin>>m>>n;
    cout<<pingguo(m,n)<<endl;
    return 0;
}
