//
//  main.cpp
//  EXP2.Q1
//
//  Created by Mark on 2020/3/12.
//  Copyright © 2020 Mark. All rights reserved.
//

#include <iostream>
using namespace std;

class Student{
    string name;
    double score;
public:
    friend bool Compare(Student, Student);
    Student(string s = "Xiao ming", double n = 98.5): name(s), score(n){}
    void setData(string, double);
    void getScore(void){
        cout<<this -> score;
    }
};

bool Compare(Student s1, Student s2){
    if(s2.score >= s1.score) return true;
    else return false;
}

void myswap(Student& s1, Student& s2){
    Student tmp = s1;
    s1 = s2;
    s2 = s1;
}

void Student::setData(string s, double n){
    name = s;
    score = n;
}

int main(int argc, const char * argv[]) {
    Student student[3];
    student[1].setData("Xiao Li", 99.5);
    student[2].setData("Xiao Fang", 55.3);
    for(int i = 0; i <= 1; i++){
        for(int j = i; j <= 1; j++){
            if(Compare(student[j], student[j+1])) myswap(student[j], student[j+1]);
        }
    }
    cout<<"最高分：";
    student[0].getScore();
    cout<<"最低分：";
    student[2].getScore();
    cout<<endl;
    return 0;
}
