//
//  main.cpp
//  test
//
//  Created by Mark on 2020/1/3.
//  Copyright © 2020 Mark. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    char pc[][10] = {"Beijing","Shanghai","Tianjin","Beijing"};
    cout<<pc[0]<<" "<<pc[3]<<endl;
    cout<<(pc[0] == pc[3])<<endl;
    return 0;
}
