#include<iostream>
using namespace std;

int cow(int m){
    int sum = 0;
    if(m <= 3) return 1;
    else{
        sum = sum + cow(m-3) + cow(m-1);
        return sum;
    }
}

int main(int argc, const char* argv[]){
    int m;
    cin>>m;
    cout<<cow(m);
    return 0;
}
