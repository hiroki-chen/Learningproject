//
//  main.cpp
//  HW3.Q1
//
//  Created by Mark on 2020/3/19.
//  Copyright © 2020 Mark. All rights reserved.
//
/*请编写程序完成如下设计
学生类，数据成员包括学号（公有）、姓名（保护）、年龄（私有）、学生数（静态）。学生数用来统计构造出来的学生对象数量。
课代表类，继承自学生类，数据包括负责课程编号（公有）、课程评分（公有）
要求使用构造初始化符表“：”的形式进行构造，每个类又相关数据的输出显示函数
在主函数中构造对象并输出显示相关数据
*/


#include <iostream>
using namespace std;

class Student{
    int alter;
protected:
    string name;
public:
    static int studentnummer;
    string id;
    Student(string a = "xiaoming", string b = "10086", int c = 18) : alter(c), name(a), id(b) {studentnummer++;}
    void print(void){
        cout<<"Name is:"<<name<<" "<<"ID is:"<<id<<" "<<endl;
    }
    static void printstudentnummber(void){cout<<"The number is:"<<studentnummer<<endl;}
};

class Studentenvertreter : public Student{
public:
    string kursnummer;
    double note;
    Studentenvertreter(string a, string b, int c, string d, double e) : Student(a, b, c) {
        kursnummer = d;
        note = e;
    }
    void print(void){
        cout<<"Name is:"<<name<<" "<<"ID is:"<<id<<endl;
        cout<<"The course number is:"<<kursnummer<<" "<<"The score is"<<note<<endl;
    }
};

int Student:: studentnummer = 0;

int main(int argc, const char * argv[]) {
    Student xiaohong("xiaohong", "10087", 23), naruto("naturo", "66666", 100), xiaoming;
    Studentenvertreter xiaochen("xiaochen", "12345", 19, "Linear Algebra", 99.9);
    xiaohong.print();
    naruto.print();
    xiaoming.print();
    xiaohong.printstudentnummber();
    xiaochen.print();
    return 0;
}
