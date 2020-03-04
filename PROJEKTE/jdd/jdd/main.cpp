#include <iostream>
const int MAXNUM = 111;
unsigned  long ww[MAXNUM*11][MAXNUM*11];
unsigned long p(int n, int max);

using namespace std;
int main(int argc, const char* argv[]){
    int n;
    cin>>n;
    cout<<p(n,n);
    return 0;
}
unsigned long p(int n, int max){
    if(n == 1 || max == 1){
        ww[n][max]=1;
        return 1;
    }
    if(n < max){
        ww[n][n]=ww[n][n] ? ww[n][n] : p(n, n);
        return ww[n][n];
    }
    if(n == max){
        ww[n][max]=ww[n][n - 1] ? 1 + ww[n][n - 1]:1 + p(n, n - 1);
        return ww[n][max];
    }
    else{
        ww[n][max]=ww[n - max][max] ? (ww[n - max][max]) : p(n - max, max);
        ww[n][max]+=ww[n][max - 1] ? (ww[n][max - 1]) : p(n, max - 1);
        return ww[n][max];
    }
}
