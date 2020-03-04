//
//  main.cpp
//  第六章作业1
//
//  Created by Mark on 2019/11/22.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int row,col;
    cin>>row>>col;
    int *MatrixA = new int [row * col];
    int *MatrixB = new int [row * col];
    int *resultmatrix = new int [row * col];
    for (int i = 0; i < row * col; i++) {
        cin>>MatrixA[i];
    }
    for (int i = 0; i < row * col; i++) {
        cin>>MatrixB[i];
    }
    for (int i = 0; i < row * col; i++) {
        resultmatrix[i] = MatrixA[i] + MatrixB[i];
    }
    int j = 1;
    for (int i = 0; i < row * col; i++) {
        if(j % col ==0) cout<<resultmatrix[i]<<" "<<endl;
        else cout<<resultmatrix[i]<<" ";
        j++;
    }
    return 0;
}

