//
//  main.cpp
//  题目6
//
//  Created by Mark on 2020/2/27.
//  Copyright © 2020 Mark. All rights reserved.
//

#include <iostream>
using namespace std;

static double sum = 0;
static int studentsum = 0;

class Student{
    int number;
    string name;
    double score;
    double avg;
public:
    void SetData(int,string,double);
    void Disp();
    static double Avg();
};
void Student::SetData(int a, string b, double c){
    number = a;
    name = b;
    score = c;
    sum += c;
    studentsum += 1;
}
double Student::Avg(){
    return sum / studentsum;
}
void Student::Disp(){
    cout<<Avg()<<endl;
}
int main(int argc, const char * argv[]) {
    Student student[5];
    int a;
    string b;
    double c;
    for (int i = 0; i <= 4; i++) {
        cin>>a>>b>>c;
        student[i].SetData(a, b, c);
    }
    student[5].Disp();
    return 0;
}
