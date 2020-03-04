#include <iostream>
using namespace std;

void maxfunc(int& x, int& y){
    if(y > x) {
        int temp = x;
        x = y;
        y = temp;
    }
}
void yuefen(int& x, int& y){
    int r;
    int tempx = x, tempy = y;
    maxfunc(tempx,tempy);
    while(tempy != 0){
        r = tempx % tempy;
        tempx = tempy;
        tempy = r;
    }
    x = x / tempx;
    y = y / tempx;
}

struct Imaginary{
    int numerator;
    int denominator;
};

struct Complex{
    int real;
    Imaginary imaginary;
};

string operator +(Complex complex1,Complex complex2){
    int real,numertor,dominator;
    Imaginary imaginary;
    real = complex1.real + complex2.real;
    dominator = complex1.imaginary.denominator * complex2.imaginary.denominator;
    numertor = complex1.imaginary.numerator * complex2.imaginary.denominator + complex2.imaginary.numerator * complex1.imaginary.denominator;
    yuefen(dominator,numertor);
    imaginary.numerator = numertor;
    imaginary.denominator = dominator;
    return to_string(real) + "+" + to_string(imaginary.numerator) + "/" + to_string(imaginary.denominator) + "i";
}

int main(int argc, const char* argv[]) {
    Complex complex1,complex2;
    cin>>complex1.real>>complex1.imaginary.numerator>>complex1.imaginary.denominator;
    cin>>complex2.real>>complex2.imaginary.numerator>>complex2.imaginary.denominator;
    cout<<(complex1+complex2)<<endl;
    return 0;
}
