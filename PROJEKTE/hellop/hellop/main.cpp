//
//  main.cpp
//  hellop
//
//  Created by Mark on 2020/2/27.
//  Copyright © 2020 Mark. All rights reserved.
//

#include <iostream>
using namespace std;

class Test{
private:
    int result;
public:
    void Init(int a, int b){
        result = a - b;
    }
    void Print(){
        cout<<result<<endl;
    }
};


int main(int argc, const char * argv[]) {
    Test a, b;
    a.Init(68,55);
    b.Init(18,36);
    a.Print();
    b.Print();
    return 0;

}
