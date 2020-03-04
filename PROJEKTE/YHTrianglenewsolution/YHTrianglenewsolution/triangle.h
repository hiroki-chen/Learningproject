//
//  triangle.h
//  YHTrianglenewsolution
//
//  Created by Mark on 2019/12/20.
//  Copyright © 2019 Mark. All rights reserved.
//

#ifndef triangle_h
#define triangle_h
#include <iomanip>
using namespace std;
void yhsj(int n){
    int** triangle = new int *[n];
    for(int i = 0; i < n; i++){
        triangle[i] = new int[i];
    }
    **triangle = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            (j == 0 || j == i) ? *(*(triangle+i)+j) = 1 : *(*(triangle+i)+j) = *(*(triangle+i-1)+j-1) + *(*(triangle+i-1)+j);
        }
    }
    cout<<setw(20)<<**triangle<<endl;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == i) cout<<*(*(triangle+i)+j)<<endl;
            else if( j == 0) cout<<setw(20-i)<<*(*(triangle+i)+j)<<" ";
            else cout<<*(*(triangle+i)+j)<<" ";
        }
    }
    delete[] triangle;
}
#endif /* triangle_h */
