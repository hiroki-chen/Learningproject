#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.1415926535;
const double co = 1 / 3.0;
const double sp = 4 / 3.0;

/*设计圆类，并以圆类为基类，派生圆柱类、圆锥类和圆球类（分别求出其面积和体积）
要求：
自行确定各类具有的数据成员、函数成员，如果需要对象成员，再自行设计相关类；
在设计程序过程中，尽量多地涉及类继承与多态性的重要概念，如虚函数、纯虚函数、抽象基类等等。
*/

class Circle{
    int radius;
public:
    Circle(int r) : radius(r) {}
    virtual void cal() = 0;
    virtual int getRadius(){
        return this -> radius;
    }
};

class Cylinder : public virtual Circle{
    int height;
public:
    Cylinder(int r, int h) : Circle(r), height(h) {}
    void cal(){
        int r = getRadius();
        double volume = r * r * pi * height;
        cout<<"The volume of cynlinder is:"<<volume<<endl;
        double area = 2 * r * pi * height;
        cout<<"The area of cynlinder is:"<<area<<endl;
    }
};

class Cone : public virtual Circle{
    int height;
public:
    Cone(int r, int h) : Circle(r), height(h){}
    void cal(){
        int r = getRadius();
        double volume = co* r * r * pi * height;
        double area = pi * r * (sqrt(pow(r, 2) + pow(height, 2)));
        cout<<"The volume of cone is:"<<volume<<endl;
        cout<<"The area of cone is:"<<area<<endl;
    }
};

class Sphere : public virtual Circle{
public:
    Sphere(int r) : Circle(r){}
    void cal(){
        int r = getRadius();
        double volume = sp * pow(r, 3);
        double area = 4 * pi * pow(r, 2);
        cout<<"The volume of sphere is:"<<volume<<endl;
        cout<<"The area of sphere is:"<<area<<endl;
    }
};

int main(int argc, const char* argv[]){
    int r;
    int h;
    cin>>r>>h;
    Cylinder cylinder(r, h);
    Cone cone(r, h);
    Sphere sphere(r);
    cylinder.cal();
    cone.cal();
    sphere.cal();
    return 0;
}