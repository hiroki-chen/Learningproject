//
//  main.cpp
//  MAXIMUM SUBSTRING SUM
//
//  Created by Mark on 2020/3/14.
//  Copyright © 2020 Mark. All rights reserved.
//
/*问题描述：
 假设存在一串整数数组，要求找到一串连续的子序列，使得它的和最大。
 */

#include <iostream>
using namespace std;

int maxSubarray(int a[], int N){ //N为数据规模
    int Max = 0, tempMax = 0;
    for(int i = 0; i < N; i++){
        tempMax += a[i];
        if(tempMax > Max) Max = tempMax; //如果tempMax比先前存储的Max大就让Max等于它
        if(tempMax < 0) tempMax = 0; //如果tempMax小于零，那么无论后面的数据怎样，都不可能使得后面的数据加上temp之后变大了，因此最大子序列不可能是tempMax了，而先前数据已存储。
    }
    return Max;
}

int main(int argc, const char * argv[]) {
    int test[6]{-9,2,1,-5,2,12};
    cout<<maxSubarray(test, 6)<<endl;
    return 0;
}
