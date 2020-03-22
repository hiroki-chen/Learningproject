//
//  main.cpp
//  HW3.Q2
//
//  Created by Mark on 2020/3/19.
//  Copyright © 2020 Mark. All rights reserved.
//
/*定义一个点Point类，数据成员是浮点型横纵坐标；定义一个颜色类Color数据成员只有颜色（字符数组#000000~#FFFFFF）；一个直线类Line，数据成员是两个Point对象，表示起点和终点（即Point两个对象为Line的内嵌对象）；一个三角形类Triangle，继承自Line和Color，数据成员有三角形的高height，三角形理解成以基类Color为颜色，以基类直线为底，以height为高的直角三角形，(即直线和高分别为两条直角边)请实现相关函数，计算三角形的颜色、周长和面积并给出相关输出。
*/

#include <iostream>
#include <cmath>
using namespace std;

class Point{
    double x;
    double y;
public:
    Point(int a, int b): x(a), y(b){}
    double getx(void){
        return x;
    }
    double gety(void){
        return y;
    }
};

class Color{
    string color;
public:
    Color(string val) : color(val){}
    string getcolor(void){
        return this -> color;
    }
};

class Line{
public:
    Point start;
    Point end;
    Line(double a, double b, double c, double d): start(a, b), end(c, d){}
};

class Triangle : public Line, public Color{
    double height;
public:
    Triangle(double a, double b, double c, double d, string val, double h) : Color(val), Line(a, b, c, d), height(h){}
    void AreaCalculator(void){
        double x1 = start.getx();
        double x2 = end.getx();
        double y1 = start.gety();
        double y2 = end.gety();
        double x = pow((x1-x2), 2);
        double y = pow((y1-y2) ,2);
        double area = 0.5 * sqrt(x + y) * height;
        double circumference = sqrt(x + y) + height + sqrt(pow(height, 2) + x + y);
        cout<<"The color of Trangle is:"<<getcolor()<<endl<<"The area of this triangle is:"<<area<<endl<<"The circumference of this triangle is:"<<circumference<<endl;
    }
};

int main(int argc, const char * argv[]) {
    double x1, x2, y1, y2;
    double height;
    string color;
    cout<<"请输入三角形的起始点的横纵坐标、颜色和高：";
    cin>>x1>>x2>>y1>>y2;
    cin>>color;
    cin>>height;
    Triangle example(x1, x2, y1, y2, color, height);
    cout<<"这个三角形的数据如下："<<endl;
    example.AreaCalculator();
    return 0;
}
