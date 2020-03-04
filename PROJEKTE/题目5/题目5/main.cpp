//
//  main.cpp
//  题目5
//
//  Created by Mark on 2020/2/27.
//  Copyright © 2020 Mark. All rights reserved.
//

#include <iostream>
using namespace std;

enum Sex{
    Male = 0,
    Female
};
class Person{
    string name = "xiao wang";
    unsigned int age = 23;
    Sex sex = Male;
public:
    Person() = default;
    Person(char a[], unsigned int b, Sex c){
        name = a;
        age = b;
        sex = c;
    }
    Person (Person &a){
        name = a.name;
        age = a.age;
        sex = a.sex;
    }
    ~Person(){
        cout<<name<<" "<<age<<" "<<sex<<endl;
    }
};

int main(int argc, const char * argv[]) {
    Person p1;
    Person p2(p1);
    Person p3("xiao ming",24,Male);
    return 0;
}
