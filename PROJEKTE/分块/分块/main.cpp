#include <iostream>
using namespace std;

double average(int** matrix, int row, int col){
    double sum = 0;
    for(int i = 0; i <row; i++){
        for(int j = 0; j < col; j++){
            sum += *(*(matrix+i)+j);
        }
    }
    return sum / (row*col);
}

int main(int argc, const char* argv[]){
    int row,col;
    cin>>row>>col;
    int** matrix = new int* [row];
    for(int i = 0; i < row; i++){
        matrix[i] = new int [col];
    }
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col; j++){
            cin>>*(*(matrix+i)+j);
        }
    }
    int x,y;
    cin>>x>>y;
    x += 1;
    y += 1;
    if((0 <= x && x < row) && (0 <= y && y < col)){
        int** m1 = new int* [x];  //*y];
        int** m2 = new int* [x];//*(col-y)];
        int** m3 = new int* [(row-x)]; //*y];
        int** m4 = new int* [(row-x)];//*(col-y)];
        for(int i = 0; i < x; i++){
            m1[i] = new int [y];
            m2[i] = new int [col-y];
        }
        for(int i = 0; i < row-x; i++){
            m3[i] = new int [y];
            m4[i] = new int [col-y];
        }
        //fuzhi.
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                m1[i][j] = *(*(matrix+i)+j);
            }
        }
        for(int i = 0; i < x; i++){
            for(int j = 0; j < col-y; j++){
                m2[i][j] = *(*(matrix+i)+j);
            }
        }
        for(int i = 0; i < row-x; i++){
            for(int j = 0; j < y; j++){
                m3[i][j] = *(*(matrix+i)+j);
            }
        }
        for(int i = 0; i < row-x; i++){
            for(int j = 0; j < col-y; j++){
                m4[i][j] = *(*(matrix+i)+j);
            }
        }
        double a[5];
        a[1] = average(m1,x,y);
        a[2] = average(m2,x,col-y);
        a[3] = average(m3,row-x,y);
        a[4] = average(m4,row-x,col-y);
        double max = 0;
        for(int i = 1; i <=4; i++){
            if(a[i] > max) max = a[i];
        }
        cout<<max;
        delete [] m1;
        delete [] m2;
        delete [] m3;
        delete [] m4;
    }
    else cout<<"WRONG INPUT!";
    return 0;
}
