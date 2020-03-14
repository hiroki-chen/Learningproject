
#include <iostream>
using namespace std;
class Rational{
    int numerator;
    int denominator;
public:
    void plus(Rational, Rational);
    void sub(Rational, Rational);
    void multi(Rational, Rational);
    void div(Rational, Rational);
    int GetNum(){return numerator;}
    int GetDenom(){return denominator;}
    void EditNum(int a){numerator = a;}
    void EditDemon(int a){denominator = a;}
    Rational(int a = 1, int b = 5): numerator(a), denominator(b){}
    ~Rational(){}
};

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

void Rational:: plus(Rational a, Rational b){
    int num_temp, den_temp;
    num_temp = a.GetNum() * b.GetDenom() + a.GetDenom() * b.GetNum();
    den_temp = a.GetDenom() * b.GetDenom();
    yuefen(num_temp, den_temp);
    numerator = num_temp;
    denominator = den_temp;
}

void Rational:: multi(Rational a, Rational b){
    Rational temp;
    int num_temp, den_temp;
    num_temp = a.GetNum() * b.GetNum();
    den_temp = a.GetDenom() * b.GetDenom();
    yuefen(num_temp, den_temp);
    numerator = num_temp;
    denominator = den_temp;
}

void Rational:: div(Rational a, Rational b){
    Rational temp;
    int num_temp, den_temp;
    num_temp = a.GetNum() * b.GetDenom();
    den_temp = a.GetDenom() * b.GetNum();
    yuefen(num_temp, den_temp);
    numerator = num_temp;
    denominator = den_temp;
}

void Rational:: sub(Rational a, Rational b){
    Rational temp;
    int num_temp, den_temp;
    num_temp = a.GetNum() * b.GetDenom() - a.GetDenom() * b.GetNum();
    den_temp = a.GetDenom() * b.GetDenom();
    yuefen(num_temp, den_temp);
    numerator = num_temp;
    denominator = den_temp;
}

int main(int argc, const char * argv[]) {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    Rational r1(a,b), r2(c,d), ans1,ans2,ans3,ans4;
    ans1.plus(r1, r2);
    ans2.sub(r1, r2);
    ans3.multi(r1, r2);
    ans4.div(r1, r2);
    if(ans1.GetNum() == ans1.GetDenom()) cout<<"SUM:"<<1<<endl;
    else if(ans1.GetNum() == 0) cout << "SUM:"<<0<<endl;
    else cout << "SUM:"<<ans1.GetNum()<<"/"<<ans1.GetDenom()<<endl;
    
    if(ans2.GetNum() == ans2.GetDenom()) cout<<"SUB:"<<1<<endl;
    else if(ans2.GetNum() == 0) cout << "SUB:"<<0<<endl;
    else cout << "SUB:"<<ans2.GetNum()<<"/"<<ans2.GetDenom()<<endl;
    
    if(ans3.GetNum() == ans3.GetDenom()) cout<<"MUL:"<<1<<endl;
    else if(ans3.GetNum() == 0) cout << "MUL:"<<0<<endl;
    else cout << "MUL:"<<ans3.GetNum()<<"/"<<ans3.GetDenom()<<endl;
    
    if(ans4.GetNum() == ans4.GetDenom()) cout<<"DIV:"<<1<<endl;
    else if(ans4.GetNum() == 0) cout << "DIV:"<<0<<endl;
    else cout << "DIV:"<<ans4.GetNum()<<"/"<<ans4.GetDenom()<<endl;
    
    return 0;
}
