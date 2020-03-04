//
//  main.cpp
//  test3333
//
//  Created by Mark on 2019/12/23.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> number(10,0);
    int n;
    for (int i = 0; i <=9; i++) {
        cin>>n;
        number[i] = n;
    }
    for (vector<int>::iterator i = number.begin(); i != number.end(); i++) {
        *i = 4 * *i;
        cout<<*i<<" ";
    }
    cout<<endl;
    for(auto& i : number){
        i = 2 * i;
    }
    for(auto i : number){ //i指的是对于number中的所有元素。
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
