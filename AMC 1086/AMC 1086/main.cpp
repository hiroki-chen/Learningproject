//
//  main.cpp
//  ACM 1086
//
//  Created by Mark on 2019/11/18.
//  Copyright © 2019 Mark. All rights reserved.
//
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int order;
    cout<<"Enter the Order of These Two Matrixes."<<endl;
    cin>>order;
    if(order >= 1 && order <=9){
        int MatrixA[order][order];
        int MatrixB[order][order];
        int resultMatrix[order][order];
    for(int i = 1;i<=order;i++){
        for (int j = 1; j<=order; j++) {
            cin>>MatrixA[i][j];
        }
    }
    cout<<"MatrixA ends here."<<endl;
    for(int i = 1;i<=order;i++){
        for (int j = 1; j<=order;j++) {
            cin>>MatrixB[i][j];
        }
    }
    
    for(int i = 1;i<=order;i++){
        for(int j = 1;j<=order;j++){
            resultMatrix[i][j] = 0;
            for(int k = 1;k<=order;k++){
                    resultMatrix[i][j] += MatrixA[i][k]*MatrixB[k][j];
            }
        }
    }
    cout<<"The result is:\n";
    for(int i = 1;i<=order;i++){
        for (int j = 1; j<=order; j++) {
            cout<<resultMatrix[i][j]<<" ";
            if(j == order) cout<<endl;
        }
    }
    }
    else cout<<"WRONG!"<<endl;
    return 0;
}
