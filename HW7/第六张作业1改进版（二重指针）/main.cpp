//
//  main.cpp
//  第六张作业1改进版（二重指针）
//
//  Created by Mark on 2019/11/22.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int row,col;
    cin>>row>>col;
    /*注意数组A[]本质上等于指针*A的效果，同样地二维数组A[][]等同于指针**A的效果；但是由于我们
     并不清楚它的长度，因此需要dynamic memory allocation，进行说明。也就是我们要对row和col进行说明。
     格式是： (维度乘以*) 变量名 = new int *[行数] 特别地，这边的new int*
     []说明了对于**A指向的*A指针的长度。于是接下来需要说明对于每个已经说明的**A的长度，进行附属的*A长度的说明（此时应用循环说明。）*/
    int **MatrixA = new int *[row];
    int **MatrixB = new int *[row];
    int **resultmatrix = new int *[row];
    for (int j = 0; j < col; j++) {
        MatrixA[j] = new int [col];
        MatrixB[j] = new int [col];
        resultmatrix[j] = new int [col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin>>MatrixA[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin>>MatrixB[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            resultmatrix[i][j] = MatrixB[i][j] + MatrixA[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if((j+1) % col != 0) cout<<resultmatrix[i][j]<<" ";
            else cout<<resultmatrix[i][j]<<" "<<endl;
        }
    }
    delete [] MatrixA;
    delete [] MatrixB;
    return 0;
}
