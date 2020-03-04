//
//  main.cpp
//  题目4
//
//  Created by Mark on 2020/2/27.
//  Copyright © 2020 Mark. All rights reserved.
//

#include <iostream>
using namespace std;

class User{
    string Name = "";
    string Pass = "";
public:
    void SetName(string s){
        Name = s;
    }
    void SetPass(string s){
        Pass = s;
    }
    string GetName(){
        return Name;
    }
    string GetPass(){
        return Pass;
    }
    User() = default;
    ~User() = default;
};

int main(int argc, const char * argv[]) {
    string name,pass;
    User user[10];
    for(int i = 0; i < 10; i++){
        cin>>name>>pass;
        user[i].SetName(name);
        user[i].SetName(pass);
    }
    cout<<"Now please search:";
    string search;
    cin>>search;
    int i = 0;
    while(i <= 9){
        if(user[i].GetName() != search) i++;
        else break;
    }
    if(i > 9) cout<<"404";
    else cout<<user[i].GetPass()<<endl;
    return 0;
}
