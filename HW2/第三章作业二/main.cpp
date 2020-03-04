//
//  main.cpp
//  第三章作业二
//
//  Created by Mark on 2019/10/12.
//  Copyright © 2019 Mark. All rights reserved.
//
#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(long); //Prototype of the function.
int main(int argc, const char * argv[]) {
    long i,j,k1,k2;
    cin>>i;
    long distance;
    long distance1, distance2;
    bool flag = false;
    int a[i];
    for (j=1; j<=i; j++) {
        cin>>a[j];
    }
    for(j=1;j<=i;j++){
        if(isPrime(a[j]) == true){
            distance = 0;
            cout<<a[j]<<" "<<distance<<endl;
        }
        else if(isPrime(a[j]) == false){
           for(k1=a[j],flag=false;k1>2 && flag == false;k1=k1-1){
                if (isPrime(k1) == true) {
                    flag = true;
                    distance1 = fabs(a[j]-k1);
                }
            }
            for(k2=a[j],flag = false;k2>2 && flag == false;k2=k2+1){
                if (isPrime(k2) == true) {
                    flag = true;
                    distance2 = fabs(a[j]-k2);
                }
            }
            if(distance1 < distance2){
                cout<<(k1+1)<<" "<<distance1<<endl;
            }
            else if (distance1 == distance2){
                cout<<(k1+1)<<" "<<distance1<<endl;
            }
            else cout<<(k2-1)<<" "<<distance2<<endl;
        }
    }
    return 0;
}
//Function Definition here.
bool isPrime(int number) {
    for (int i = 2; i * i <= number; i++){
        if (number % i == 0) return false;
    }
    return true;
}
